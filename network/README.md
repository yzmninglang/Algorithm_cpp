# 网络协议与算法维度观察示例

本目录包含 gRPC、WebSocket 以及 Swin Transformer 算法维度的观察示例。

---

## 1. gRPC 示例

### 启动步骤
1. **启动 Server**:
   ```bash
   cd network
   python server.py
   ```
2. **运行 Client**:
   ```bash
   cd network
   python client.py
   ```

### 文件说明
- `messenger.proto`: 定义服务接口。
- `server.py`: 服务端实现。
- `client.py`: 客户端实现。
- `messenger_pb2.py` & `messenger_pb2_grpc.py`: 自动生成的代码。

---

## 2. WebSocket 示例

### 启动步骤
1. **启动 Server**:
   ```bash
   cd network
   python ws_server.py
   ```
2. **运行 Client**:
   ```bash
   cd network
   python ws_client.py
   ```

### 文件说明
- `ws_server.py`: 基于 `websockets` 的服务端。
- `ws_client.py`: 客户端实现。

---

## 3. Swin Transformer 维度观察

专门用于观察相对位置偏置 (Relative Position Bias) 的维度变换过程。

### 运行演示
在根目录下运行：
```bash
python swin_bias_demo.py
```

### 观察重点
脚本会逐步打印以下维度的变化：
1. **Bias Table**: `( (2*Wh-1)*(2*Ww-1), nH )`
2. **Index**: `( Wh*Ww, Wh*Ww )`
3. **查表后**: `( (Wh*Ww*Wh*Ww), nH )`
4. **View 还原**: `( Wh*Ww, Wh*Ww, nH )`
5. **Permute 最终**: `( nH, Wh*Ww, Wh*Ww )`

---

## 4. Swin Transformer Window Partition 维度观察

专门用于观察如何将大图切分为小窗口。

### 运行演示
在根目录下运行：
```bash
python swin_window_demo.py
```

### 观察重点
脚本会逐步打印以下维度的变化：
1. **输入**: `(B, H, W, C)`
2. **View 拆分**: `(B, H//ws, ws, W//ws, ws, C)`
3. **Permute 调整**: `(B, H//ws, W//ws, ws, ws, C)`
4. **View 合并**: `(B * num_windows, ws, ws, C)`

---

## 5. MAE/ViT Decoder Recovery (Unpatchify) 维度观察

专门用于观察如何将 Patch 特征恢复为原始图像。

### 运行演示
在根目录下运行：
```bash
python decoder_recovery_demo.py
```

### 观察重点
脚本会演示两种恢复方式：
1. **Linear + Unpatchify (MAE 风格)**:
   - `Linear`: 将特征映射到像素空间 `(B, L, P*P*C)`。
   - `Reshape`: 拆分为 5D 张量 `(B, H//P, W//P, P, P, C)`。
   - `Einsum`: 调整维度顺序 `(B, C, H//P, P, W//P, P)`。
   - `Final Reshape`: 还原为图像 `(B, C, H, W)`。
2. **Conv 恢复**:
   - `View`: 还原到网格 `(B, H//P, W//P, D)`。
   - `Conv2d`: 预测像素。


