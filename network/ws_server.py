import asyncio
import websockets

async def echo(websocket):
    print(f"客户端已连接: {websocket.remote_address}")
    try:
        async for message in websocket:
            print(f"收到来自客户端的消息: {message}")
            reply = f"服务端已收到: {message}"
            await websocket.send(reply)
            print(f"已发送回复: {reply}")
    except websockets.exceptions.ConnectionClosedOK:
        print("客户端正常断开连接")
    except Exception as e:
        print(f"发生错误: {e}")
    finally:
        print(f"连接关闭: {websocket.remote_address}")

async def main():
    async with websockets.serve(echo, "localhost", 18765):
        print("WebSocket Server 正在启动，监听端口 8765...")
        await asyncio.Future()  # 运行直到被取消

if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("Server 已停止")
