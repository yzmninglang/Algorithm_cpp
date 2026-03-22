import asyncio
import websockets

async def hello():
    uri = "ws://localhost:18765"
    async with websockets.connect(uri) as websocket:
        name = "KiloCode"
        message = f"你好，我是 {name}，这是通过 WebSocket 发送的消息！"
        
        print(f"正在发送消息: {message}")
        await websocket.send(message)
        
        response = await websocket.recv()
        print(f"收到服务器回复: {response}")

if __name__ == "__main__":
    try:
        asyncio.run(hello())
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f"连接失败: {e}")
