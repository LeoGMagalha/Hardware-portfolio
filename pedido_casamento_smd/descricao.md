# Pedido de casamento
Sequência de LED's escrito "Casa comigo ?"  acendendo em duas cenas possíveis e um coração acendendo separadamente. Criei esse circuito para fazer o pedido de casamento a minha noiva.

### Arquivos importantes nessa pasta

- pedido_casamento_smd.kicad* - arquivos do projeto no KiCAD;
- pedido_casamento_smd_gbr.rar - arquivos gerber para fabricação da PCB;
- esquematico.pdf - esquemático em formato PDF, também pode ser visualizado no KiCAD pelo arquivo pedido_casamento_smd.kicad_sch;
- *.png, *.jpg ou *.mp4, imagens e vídeos sobre o projeto.

### Imagens 3D geradas no KiCAD: 

![Captura de tela 2024-02-14 210953](C:\Users\leona\OneDrive\Drive\Projeto Engenheiro de Hardware\Hardware-portfolio\pedido_casamento_smd\Captura de tela 2024-02-14 210953.png) 

![Captura de tela 2024-02-14 211134](C:\Users\leona\OneDrive\Drive\Projeto Engenheiro de Hardware\Hardware-portfolio\pedido_casamento_smd\Captura de tela 2024-02-14 211134.png)

### Protótipo

![IMG_20221209_104448](C:\Users\leona\OneDrive\Drive\Projeto Engenheiro de Hardware\Hardware-portfolio\pedido_casamento_smd\IMG_20221209_104448.jpg)

![WhatsApp Image 2024-02-14 at 21.27.28](C:\Users\leona\OneDrive\Drive\Projeto Engenheiro de Hardware\Hardware-portfolio\pedido_casamento_smd\WhatsApp Image 2024-02-14 at 21.27.28.png)

### Vídeo de funcionamento do protótipo:



### Componentes utilizados

- 555 em configuração astável
  - Atua como clock de frequência ajustável, com um trimpot.
- Contadores Década (CI4017)
  - Atuam tanto no acionamento dos LED's, quanto na seleção de cenas e no acionamento de transistores.
- Portas lógicas 
  - 74LS08 - AND
  - 74HC04 - NOT
  - 74LS32 - OR
  - São responsáveis pela lógica das cenas e também da orquestração da rede de contadores década, também fazem interface com os LED's.
- Transístores (2N2222 ou BC549)
  - Reponsáveis pela expansão de conexões para o contador década que acende os LED	'S da frase,  dado que o contador tem 10 saídas, são utilizados 6 transístores no total.

### Status do projeto

- Concluído