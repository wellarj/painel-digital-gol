import asyncio
import websockets
import json
import random

async def send_sensor_data(websocket, path):
    sensors = {
        "velocidade": lambda: random.randint(0, 200),
        "contaGiros": lambda: random.randint(0, 8000),
        "nivelCombustivel": lambda: random.randint(0, 100),
        "temperaturaMotor": lambda: random.randint(0, 120),
        "luzesFarol": lambda: random.choice(['on', 'off']),
        "setas": lambda: random.choice(['left', 'right']),
        "alertas": lambda: random.choice(['alerta', 'normal']),
    }
    
    while True:
        data = {key: func() for key, func in sensors.items()}
        await websocket.send(json.dumps(data))
        await asyncio.sleep(1)  # Atualiza a cada 1000 milissegundos (1 segundo)

async def main():
    async with websockets.serve(send_sensor_data, "localhost", 8080):
        await asyncio.Future()  # Run forever

if __name__ == "__main__":
    asyncio.run(main())
