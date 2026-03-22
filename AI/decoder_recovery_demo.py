import torch
import torch.nn as nn

class DecoderRecoveryDemo:
    def __init__(self, img_size=(224, 224), patch_size=16, embed_dim=768, out_chans=3):
        self.img_size = img_size
        self.patch_size = patch_size
        self.embed_dim = embed_dim
        self.out_chans = out_chans
        
        # 模拟 decoder_pred_linear: 将 embed_dim 映射到 patch 像素空间 (P*P*C)
        self.decoder_pred_linear = nn.Linear(embed_dim, patch_size * patch_size * out_chans)
        
        # 模拟 decoder_pred_conv
        self.decoder_pred_conv = nn.Conv2d(embed_dim, out_chans, kernel_size=1)
        
        # 模拟 norm
        self.norm_image = nn.LayerNorm(embed_dim)

    def recovery_linear_demo(self, x):
        """
        演示基于 Linear + Unpatchify 的恢复过程 (MAE 风格)
        x: (B, L, D) 其中 L 是 patch 数量
        """
        print(f"--- Linear Recovery (Unpatchify) 开始 ---")
        print(f"输入维度 (B, L, D): {x.shape}")
        
        # 1. Linear 映射
        x = self.decoder_pred_linear(x)
        print(f"1. Linear 映射后维度: {x.shape} (B, L, P*P*C)")
        
        # 2. Reshape 为 5D 张量
        # B, num_patches_h, num_patches_w, patch_h, patch_w, out_chans
        num_h = self.img_size[0] // self.patch_size
        num_w = self.img_size[1] // self.patch_size
        x = x.reshape(shape=(x.shape[0], num_h, num_w, self.patch_size, self.patch_size, self.out_chans))
        print(f"2. Reshape 后维度: {x.shape}")
        print(f"   (B, H//P, W//P, P, P, C)")
        
        # 3. Einsum 调整维度顺序
        # 原始: n(B), h(H//P), w(W//P), p(P), q(P), c(C)
        # 目标: n(B), c(C), h(H//P), p(P), w(W//P), q(P) -> 这样合并后就是 (B, C, H, W)
        x = torch.einsum('nhwpqc->nchpwq', x)
        print(f"3. Einsum 变换后维度: {x.shape}")
        print(f"   (B, C, H//P, P, W//P, P)")
        
        # 4. 最终 Reshape 还原图像
        x = x.reshape(x.shape[0], self.out_chans, self.img_size[0], self.img_size[1])
        print(f"4. 最终还原维度: {x.shape} (B, C, H, W)")
        return x

    def recovery_conv_demo(self, x):
        """
        演示基于 Conv 的恢复过程
        x: (B, L, D)
        """
        print(f"\n--- Conv Recovery 开始 ---")
        print(f"输入维度 (B, L, D): {x.shape}")
        
        # 1. View 还原到网格
        num_h = self.img_size[0] // self.patch_size
        num_w = self.img_size[1] // self.patch_size
        x = x.view(-1, num_h, num_w, self.embed_dim)
        print(f"1. View 还原网格维度: {x.shape} (B, H//P, W//P, D)")
        
        # 2. Permute 为 Conv2d 准备 (B, C, H, W)
        x = x.permute(0, 3, 1, 2)
        print(f"2. Permute 后维度: {x.shape} (B, D, H//P, W//P)")
        
        # 3. Conv 预测
        x = self.decoder_pred_conv(x)
        print(f"3. Conv 预测后维度: {x.shape} (B, C, H//P, W//P)")
        
        # 4. Norm 过程 (通常在特征空间做)
        # 这里演示代码中的 permute -> norm -> permute
        x = x.permute(0, 2, 3, 1) # (B, H//P, W//P, C) -> 假设这里 norm 的是 C
        # 注意：原代码中 norm 的是 embed_dim，这里为了演示流程
        print(f"4. Norm 变换流程演示完毕")
        
        return x

if __name__ == "__main__":
    img_size = (224, 224)
    patch_size = 16
    embed_dim = 768
    num_patches = (img_size[0] // patch_size) * (img_size[1] // patch_size)
    
    # 模拟输入 (B=2, L=196, D=768)
    x = torch.randn(2, num_patches, embed_dim)
    
    demo = DecoderRecoveryDemo(img_size, patch_size, embed_dim)
    
    # 演示 Linear 恢复
    demo.recovery_linear_demo(x)
    
    # 演示 Conv 恢复
    demo.recovery_conv_demo(x)
