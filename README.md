<h1 align="center"> :fish: Eco-Ocean: Radar de Lixo :ocean: </h1>

## Índice :page_with_curl:

  * [Descrição do Projeto](#descrição-do-projeto-memo)
     * [Introdução](#introdução-page_facing_up)
     * [Radar de Lixo](#radar-de-lixo-wastebasket)
     * [Futuro do Projeto](#futuro-do-projeto-sparkles)
  * [Acesso ao projeto](#acesso-ao-projeto-file_folder)
  * [Ferramenta utilizada](#ferramenta-utilizada-hammer_and_wrench)
  * [Bibliotecas utilizadas](#bibliotecas-utilizadas-books)
  * [Componentes necessários](#componentes-necessários-toolbox)
  * [Montagem](#montagem-wrench)
     * [Cuidados durante a montagem](#cuidados-durante-a-montagem-warning)
  * [Reprodução](#reprodução-gear)
  * [Pessoas Desenvolvedoras do Projeto](#pessoas-desenvolvedoras-do-projeto-globe_with_meridians)

## Descrição do projeto :memo:

### Introdução :page_facing_up:
<p align="justify">Nos últimos anos, os oceanos têm enfrentado sérios problemas de poluição, principalmente devido ao descarte inadequado de resíduos por parte dos seres humanos. Desde lixos deixados nas praias, que são levados pelas ondas para o oceano, até resíduos industriais descartados de forma incorreta, a saúde dos ecossistemas marinhos está ameaçada. Diante dessa problemática, nosso grupo, chamado ECO-AFFAIRS, propõe o desenvolvimento de um “radar de lixo” com o objetivo de localizar detritos flutuantes ou submersos no oceano. Essa tecnologia permitirá que pessoas a bordo de navios de coleta de lixo, ONGs e indivíduos engajados na limpeza dos mares possam identificar e remover esses resíduos de maneira mais eficiente.</p>

### Radar de Lixo :wastebasket:
<p align="justify">O radar de lixo tem como objetivo detectar resíduos no oceano. Neste modelo inicial, estamos focando na detecção de objetos, sem a capacidade de distinguir se esses objetos são realmente lixo ou não. O projeto utiliza o sensor de distância ultrassônico HC-SR04, que é capaz de medir com precisão distâncias entre 3 cm e 400 cm.</p>
<p align="justify">Ao ligar o dispositivo, o  sensor HC-SR04 emite um pulso ultrassônico. Esse pulso reflete em um objeto (que pode ser lixo ou outro objeto qualquer) e retorna ao sensor. Com base no tempo de ida e volta do pulso, calculamos a distância até o objeto. Se a distância for menor que 20 cm, o LCD exibirá “Lixo detectado!” e o LED vermelho acenderá. Caso contrário, o LCD mostrará “Nada detectado!” e o LED verde indicará que não há lixo próximo.</p>

### Futuro do Projeto :sparkles:
<p align="justify">No processo contínuo de desenvolvimento do projeto, planejamos substituir o Arduino UNO pelo ESP32. Essa mudança permitirá que os dados capturados pelo radar de lixo sejam enviados para um programa em Python, que, por sua vez, os encaminhará para um banco de dados e criará gráficos com base nos dados coletados de todos os outros radares de lixo. Alguns dos indicadores que pretendemos apresentar são:</p>

* <strong> Taxa de Acerto do Radar: </strong> Indicará se o radar de lixo detectou corretamente se o detrito encontrado era realmente lixo. Essa métrica é importante para avaliar a eficácia do sistema;
* <strong> Lixo Encontrado por Dia: </strong> Mostrará a quantidade total coletada por dia;
* <strong> Lixo Encontrado por Região: </strong> Indicará a quantia total encontrada em uma determinada região. Por exemplo: *“20 kg de lixo foram encontrados próximo à região litorânea de Santos”*. Isso ajudará a direcionar esforços de limpeza e conscientização.

<p align="justify">Além disso, esses dados serão disponibilizados em um site informativo com o objetivo de informar o público em geral, especialmente aqueles que vivem nas regiões costeiras. Também queremos sensibilizar as empresas que dependem financeiramente dos oceanos e destacar a importância de combater a poluição causada pelos seres humanos. O site também promoverá o radar de lixo, incentivando mais pessoas a participarem da coleta de lixo nos oceanos. A longo prazo, esperamos reduzir significativamente a poluição marinha causada por resíduos.</p>
<p align="justify">Por fim, nos estágios iniciais do projeto, a coleta de dados será realizada manualmente, uma vez que a taxa de acerto do radar não será tão precisa no começo. Isso será feito por meio da detecção do radar, que automaticamente armazenará o horário e a data da detecção. O usuário que estiver utilizando o sistema preencherá se o objeto detectado realmente é lixo ou não, além de informar sua localização aproximada. Para automatizar ainda mais esse processo, planejamos utilizar o ESP32 com câmera embutida para treinar o radar a detectar visualmente o lixo, mesmo quando submerso no oceano. Com isso, acreditamos que isso nos permitirá aumentar a precisão do radar de lixo no futuro e automatizar ainda mais o processo de coleta de dados. </p>

## Acesso ao projeto :file_folder:

Você pode acessar o [código do projeto](radarLixo.cpp) ou a [simulação feita no Wooki](https://wokwi.com/projects/399244694477130753)

## Ferramenta utilizada :hammer_and_wrench:

- ``Arduino IDE``

## Bibliotecas utilizadas :books:

- ``LiquidCrystal_I2C``
- ``Wire``

## Componentes necessários :toolbox:

|   Componente   | Quantidade |
|:--------------:|:----------:|
| Arduino Uno R3 |      1     |
| 220 Ω Resistor |      2     |
|    LED verde   |      1     |
|  LED vermelho  |      1     |
|  Sensor de distância ultrassônico HC-SR04  |      1     |
|   LCD 16x2 com módulo I2C    |      1     |
|      Cabo      |     12     |
|    Cabo USB    |      1     |

## Montagem :wrench:

<details>
  <summary>Imagem da Montagem</summary>
  <img src="https://github.com/AliceSBulhoes/GS-ECO-OCEAN/assets/101829188/25743e89-43e3-4e9a-b139-e0c86de3f578" alt="imagem-montagem">
</details>

<h3>Cuidados durante a montagem :warning:</h3>

- ``1.`` Conectando os LED’s:
   - ``1.1.`` Possuem polaridade, então precisamos ter cuidado na hora de conectar-los aos cabos;
   - ``1.2.`` O LED possui um terminal maior, que tem polaridade positiva, e o lado do terminal menor tem polaridade negativa. Portanto, conectamos a conexão do Arduino no terminal positivo (Ânodo) e o GND no terminal negativo (Catodo);

- ``2.`` Conectando o HC-SR04:
  - ``2.1.`` Conecte o VCC no terminal positivo (5V), GND no terminal negativo (GND), o TRIG no pino 3 e no ECHO no pino 2;

- ``3.`` Conectando o LCD:
  - ``3.1.`` **Atenção!** Estamos utilizando um LCD 16x2 com um módulo I2C!;
  - ``3.2.`` Conecte o VCC no terminal positivo (5V), GND no terminal negativo (GND), o SDA no pino do Arduino A4 e o SCL no A5;
  - ``3.3.`` Teste para ver se o display está funcionando, se tiver problemas com o display, pode ser algumas dessas possibilidades: o LCD está quebrado, com mal contato ou o contraste está baixo;
    - ``3.3.1.`` Para aumentar o contraste do display basta girar o trimpot de ajuste do contraste no sentido anti-horário. Por sua vez, para diminuir o contraste gire no sentido horário.
      <details>
        <summary>Imagem de onde fica o trimpot de ajuste do contraste</summary>
        <img src="https://github.com/AliceSBulhoes/GS-ECO-OCEAN/assets/101829188/d20125d7-4a07-4d44-b6c6-d400f683bab2" alt="Trimpot de ajuste">
      </details>
      
## Reprodução :gear:

- ``1.`` Após a montagem do projeto, é necessário inserir o código por meio de um computador que possui o programa Arduino IDE instalado;
- ``2.`` Baixe as [bibliotecas necessárias](#bibliotecas-utilizadas-books) no Arduino IDE; 
- ``3.`` Transferir o código do computador para  o Arduino por meio do Cabo USB;
- ``4.`` Testar para ver se está funcionando;
- ``5.`` Com tudo montado e pronto, é necessário levá-lo para o ambiente em que será implementado e ligá-lo á uma fonte;

## Pessoas Desenvolvedoras do Projeto :globe_with_meridians:

| [<img src="https://avatars.githubusercontent.com/u/101829188?v=4" width=115><br><sub>Alice Santos Bulhões</sub>](https://github.com/AliceSBulhoes) |  [<img src="https://avatars.githubusercontent.com/u/163866552?v=4" width=115><br><sub>Eduardo Oliveira Cardoso Madid</sub>](https://github.com/EduardoMadid) |  
| :---: | :---: | 
| RM:554499 | RM:556349 | 

