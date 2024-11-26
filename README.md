# Mapa de Calor calculando dBm de sinal WiFi

## Link para assistir ao vídeo da ponderada
[Acesse o Google Drive](https://drive.google.com/drive/folders/1uvxxLlFaP7wz1_7ol16ywyK8hSIS-L6K?usp=sharing)

## Materiais

| Componente         | Quantidade | Descrição                                                                 |
|---------------------|------------|---------------------------------------------------------------------------|
| ESP32              | 2          | Microcontrolador com suporte a Wi-Fi e MQTT                              |
| Antena     | 1          | Antena para aumentar o alcance do Wi-Fi                                      |
| Protoboard         | 1          | Para facilitar as conexões                                              |

---

## Conexões

| ESP32  | Componente       | Descrição                                |
|------------|------------------|------------------------------------------|
| Espaço para antena do ESP32     | Antena    | Antena para aumentar o alcance na busca por wi-fi do nosso ESP32                 |

## Código e confecção
#### Código para o ESP32 ser capaz de emitir as informações para o Adafruit IO:
<td align="center"><a href="Semana07/Semana07.ino"><img style="border-radius: 10%; width: 100px; height: 100px;" src="assets/Arduino.png" alt="" /><br><sub><b>Código para o Arduino</b></sub></a></td>

#### Adafruit IO
<td align="center"><a href="https://io.adafruit.com/LilFer777/overview"><img style="border-radius: 10%; width: 100px; height: 100px;" src="assets/Adafruit.png" alt="" /><br><sub><b></b></sub></a></td>
Para criar uma dashboard para visualização como a que desejamos, precisamos nos cadastrar no Adafruit IO e fornecer as informações como key e usuário, que serão únicas para cada novo usuário. A criação da visualização será feita a partir do próprio código, com o endpoint que informarmos por lá. 

## Autor 
 <td align="center"><a href="https://www.linkedin.com/in/fernando-soares-oliveira/"><img style="border-radius: 10%; width: 100px; height: 100px;" src="assets/Fernando.png" alt="" /><br><sub><b>Fernando Oliveira</b></sub></a></td>
