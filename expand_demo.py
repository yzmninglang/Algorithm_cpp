import torch

def demo_expand():
    # 创建一个 2D Tensor，形状为 (1, 3)
    # expand 通常用于将维度为 1 的 Tensor 扩展到更大的尺寸
    x = torch.tensor([[1, 2, 3]])
    
    print("--- 原始 Tensor ---")
    print(f"Value:\n{x}")
    print(f"Shape: {x.shape}")
    print()

    # 将 (1, 3) 扩展为 (4, 3)
    # 注意：expand 不会分配新内存，只是在现有内存上创建新的视图
    x_expanded = x.expand(4, 3)
    print("--- x.expand(4, 3) ---")
    print("将第 0 维从 1 扩展到 4")
    print(f"Value:\n{x_expanded}")
    print(f"Shape: {x_expanded.shape}")
    print()

    # 结合 unsqueeze 和 expand
    # 原始形状 (3,) -> unsqueeze(0) -> (1, 3) -> expand(2, 3) -> (2, 3)
    y = torch.tensor([10, 20, 30])
    print("--- 原始向量 y ---")
    print(f"Value: {y}, Shape: {y.shape}")
    
    y_unsqueezed = y.unsqueeze(0)
    print(f"After unsqueeze(0): {y_unsqueezed.shape}")
    
    y_final = y_unsqueezed.expand(2, 3)
    print("--- y.unsqueeze(0).expand(2, 3) ---")
    print(f"Value:\n{y_final}")
    print(f"Shape: {y_final.shape}")
    print()

    # 使用 -1 表示保持该维度不变
    z = torch.tensor([[1], [2]]) # (2, 1)
    z_expanded = z.expand(-1, 4) # 保持第 0 维为 2，扩展第 1 维到 4
    print("--- z.expand(-1, 4) ---")
    print(f"Original Shape: {z.shape}")
    print(f"Value:\n{z_expanded}")
    print(f"Shape: {z_expanded.shape}")

if __name__ == "__main__":
    demo_expand()
