# Painel Digital Gol

Este repositório contém um painel digital para visualizar dados de sensores de um carro. O projeto inclui:

- **Página HTML** com gráficos atualizados em tempo real usando a biblioteca Chart.js.
- **Código Python** para simular dados de sensores e enviar para o WebSocket.
- **Código Arduino** para ler os dados dos sensores analógicos e enviá-los pela porta Serial.

## Estrutura do Projeto

- `index.html`: Página HTML que exibe gráficos dos dados dos sensores.
- `sensor_simulation.py`: Script Python que simula os dados dos sensores e os envia para um servidor WebSocket.
- `arduino_code.ino`: Código para o Arduino que lê os dados dos sensores analógicos e os envia pela porta Serial.

## Instruções para Uso

1. **Preparar o Ambiente:**
   - Clone o repositório.
   - Instale as dependências necessárias (Chart.js, bibliotecas Python).

2. **Configurar o Arduino:**
   - Carregue o código Arduino (`arduino_code.ino`) na placa Arduino.
   - Conecte os sensores aos pinos analógicos especificados no código.

3. **Configurar o Python:**
   - Execute o script Python (`sensor_simulation.py`) para iniciar o servidor WebSocket.
   - Certifique-se de que a porta Serial no script Python está correta.

4. **Iniciar o Servidor Web:**
   - Navegue até o diretório onde está o `index.html` e execute um servidor HTTP (por exemplo, com `python -m http.server 8000`).

5. **Acessar a Página Web:**
   - Abra um navegador e acesse `http://localhost:8000` para visualizar os gráficos em tempo real.

## Licença

Este projeto é licenciado sob a MIT License. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.