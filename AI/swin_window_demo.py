import torch

def window_partition_demo(x, window_size):
    """
    演示 Swin Transformer 的 Window Partition 过程
    Args:
        x: (B, H, W, C)
        window_size (int): 窗口大小
    """
    B, H, W, C = x.shape
    print(f"--- Window Partition 开始 ---")
    print(f"输入维度 (B, H, W, C): {x.shape}")
    print(f"窗口大小: {window_size}")
    print("-" * 30)

    # 步骤 1: View 拆分 H 和 W
    # H -> (H // window_size, window_size)
    # W -> (W // window_size, window_size)
    x = x.view(B, H // window_size, window_size, W // window_size, window_size, C)
    print(f"1. View 拆分后维度: {x.shape}")
    print(f"   (B, H//ws, ws, W//ws, ws, C)")

    # 步骤 2: Permute 调整顺序
    # 目标是将 (H//ws) 和 (W//ws) 放到前面，将两个 ws 放到一起
    # 原始索引: 0:B, 1:H//ws, 2:ws, 3:W//ws, 4:ws, 5:C
    # 调整后: 0, 1, 3, 2, 4, 5
    x = x.permute(0, 1, 3, 2, 4, 5).contiguous()
    print(f"2. Permute 后维度: {x.shape}")
    print(f"   (B, H//ws, W//ws, ws, ws, C)")

    # 步骤 3: View 合并 Batch 和 Window 数量
    # num_windows = (H // window_size) * (W // window_size)
    windows = x.view(-1, window_size, window_size, C)
    print(f"3. 最终 View 合并维度: {windows.shape}")
    print(f"   (B * num_windows, ws, ws, C)")
    
    return windows

if __name__ == "__main__":
    # 模拟输入: Batch=2, H=14, W=14, C=3
    # 窗口大小: 7
    B, H, W, C = 2, 14, 14, 3
    window_size = 7
    
    x = torch.randn(B, H, W, C)
    result = window_partition_demo(x, window_size)
    
    print("-" * 30)
    num_windows = (H // window_size) * (W // window_size)
    print(f"预期 Window 数量: {num_windows} (每个样本)")
    print(f"预期最终 Batch 维度: {B * num_windows}")
    print(f"最终输出维度: {result.shape}")
