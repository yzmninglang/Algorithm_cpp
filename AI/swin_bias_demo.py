import torch
import torch.nn as nn

class RelativePositionBiasDemo:
    def __init__(self, window_size=(7, 7), num_heads=8):
        """
        初始化相对位置偏置演示类
        Args:
            window_size: 窗口大小 (Wh, Ww)
            num_heads: 注意力头数 nH
        """
        self.window_size = window_size
        self.num_heads = num_heads
        
        # 1. 初始化 relative_position_bias_table
        # 范围是 [-Wh+1, Wh-1] 和 [-Ww+1, Ww-1]，所以大小是 (2Wh-1) * (2Ww-1)
        table_size = (2 * window_size[0] - 1) * (2 * window_size[1] - 1)
        self.relative_position_bias_table = nn.Parameter(
            torch.zeros(table_size, num_heads)
        )
        # 随机初始化以便观察
        nn.init.trunc_normal_(self.relative_position_bias_table, std=.02)
        
        print(f"--- 初始化 ---")
        print(f"窗口大小: {window_size}")
        print(f"注意力头数: {num_heads}")
        print(f"Bias Table 维度: {self.relative_position_bias_table.shape} ( (2*Wh-1)*(2*Ww-1), nH )")
        print("-" * 30)

        # 2. 生成 relative_position_index (简化版，直接模拟索引)
        # 实际 Swin 中这部分是预先计算好的，这里我们模拟一个对应的 index 张量
        # 维度应该是 (Wh*Ww, Wh*Ww)
        num_tokens = window_size[0] * window_size[1]
        self.relative_position_index = torch.randint(0, table_size, (num_tokens, num_tokens))
        print(f"Relative Position Index 维度: {self.relative_position_index.shape} ( Wh*Ww, Wh*Ww )")
        print("-" * 30)

    def forward_step_by_step(self):
        print("--- 开始执行维度变换观察 ---")
        
        # 步骤 1: 根据索引从 table 中取值
        # self.relative_position_index.view(-1) 展平索引
        flat_index = self.relative_position_index.view(-1)
        print(f"1. 展平索引维度: {flat_index.shape} ( Wh*Ww * Wh*Ww )")
        
        # 从 table 中查表
        # self.relative_position_bias_table[flat_index]
        bias_from_table = self.relative_position_bias_table[flat_index]
        print(f"2. 查表后维度: {bias_from_table.shape} ( (Wh*Ww*Wh*Ww), nH )")
        
        # 步骤 2: View 还原到 (Wh*Ww, Wh*Ww, nH)
        Wh, Ww = self.window_size
        relative_position_bias = bias_from_table.view(Wh * Ww, Wh * Ww, -1)
        print(f"3. View 还原维度: {relative_position_bias.shape} ( Wh*Ww, Wh*Ww, nH )")
        
        # 步骤 3: Permute 变换维度到 (nH, Wh*Ww, Wh*Ww)
        # 这样可以直接加到 Attention Score (nH, Wh*Ww, Wh*Ww) 上
        relative_position_bias = relative_position_bias.permute(2, 0, 1).contiguous()
        print(f"4. Permute 后维度: {relative_position_bias.shape} ( nH, Wh*Ww, Wh*Ww )")
        
        return relative_position_bias

if __name__ == "__main__":
    # 实例化并观察
    demo = RelativePositionBiasDemo(window_size=(7, 7), num_heads=8)
    result = demo.forward_step_by_step()
    print("-" * 30)
    print(f"最终输出维度: {result.shape}")
