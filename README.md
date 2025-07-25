# 💡 Controle de LED via Web com ESP32-C3 Super Mini

Este projeto demonstra como criar uma interface web simples para **ligar e desligar um LED** usando um **ESP32-C3 Super Mini** conectado à sua rede Wi-Fi.

---

## 📷 Imagens do Projeto

<div align="center">
  <img src="./imagens/esp32c3_pinos.jpg" alt="Pinos do ESP32-C3 Super Mini" width="400"/>
  <br><br>
  <img src="./imagens/projeto_pronto.jpg" alt="Projeto montado" width="400"/>
</div>

---

## ⚙️ Funcionalidades

- Conexão automática com sua rede Wi-Fi
- Criação de um servidor web local (porta 80)
- Interface com botões para controle do LED
- Feedback serial indicando status do LED

---

## 🧰 Componentes Necessários

| Componente              | Quantidade | Descrição                                |
|-------------------------|------------|------------------------------------------|
| ESP32-C3 Super Mini     | 1          | Microcontrolador com Wi-Fi integrado     |
| LED (5mm)               | 1          | Indicador visual                         |
| Resistor 220Ω           | 1          | Limitador de corrente para o LED         |
| Protoboard + Jumpers    | 1          | Para montagem dos componentes            |
| Cabo USB-C              | 1          | Para alimentar e programar o ESP32       |

---

## 🔌 Esquema de Ligação

- **LED positivo (anodo)** → GPIO 2 do ESP32-C3
- **LED negativo (catodo)** → Resistor 220Ω → GND

> O LED será controlado diretamente pelo pino 2 (D2), com proteção do resistor.

---

## 🌐 Como Usar

1. Conecte o ESP32-C3 ao computador e abra o código na Arduino IDE.
2. Preencha suas credenciais Wi-Fi no código:
   ```cpp
   const char* ssid = "SEU_SSID";
   const char* password = "SUA_SENHA";
