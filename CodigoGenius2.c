/* codigo del projecto */
/* copyright LULUCEALcoding© */
#include <htc.h>
#define _XTAL_FREQ 4000000
#define RESTART RA5
#define SERIAL TX    //BUZZER
#define BT0 RB0
#define BT1 RB3
#define BT2 RB4
#define BT3 RB5
#define LED0 RA3
#define LED1 RA2
#define LED2 RA1
#define LED3 RA0
#define f1A 450  //frequencias numeroLed NotaMusical
#define f2F 300
#define f3D 600
#define f0B 150
#define MAX_PADRAO 40
					 //frequencia da serial = 1.2kbits/s
//para transmitir qualquer byte, devemos joga-lo no TXREG, imediatamente ele será ENVIADO
//o nome do bit cuja mesma posição é a do RB2 é TX(para efeitos de serial)
void Inicializa()//PRECISA CONFIGURAR O SERIAL E A PORTA DE RESET PARA COMEÇAR COMO START, POSTERIORMENTE ELA DEVE VIRAR UM RESET
{
	TXSTA = b'00100100';//registrador para configurar o serial
	RCSTA = b'10000000';//registrador para configurar o serial
	TRISA = b'00001111';// 0 = entrada; 1 = saida
	TRISB = b'00111001';// 0 = entrada; 1 = saida
	MCLRE = b'0'; // config. RA5 como input  0 = MCLRbarrado  1 = digital input
}


void TocaBuzzer(int nLed)//cada led toca um som diferente, nLED = -1 (som de erro)
{
   switch(nLed)
   {
   int i, j;
	case 1:
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'11001000'; //freq. aproximadamente 450hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		break;
	case 2:
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10001000'; //freq. aproximadamente 300hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		break:
	case 3:
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10101010'; //freq. aproximadamente 600hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		break;
	case 0:
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10000000'; //freq. aproximadamente 150hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		break;
	case 4:         //ÇaPorra não existe. Só serve para saber que passou de nível.
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10011000'; //freq. aproximadamente ???hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10010011'; //freq. aproximadamente ???hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		break;
	case 5:         //ÇaPorra não existe. Só serve para saber que perdeu!!!
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'11011001'; //freq. aproximadamente ???hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10111011'; //freq. aproximadamente ???hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		break;
	case 6:         //ÇaPorra não existe. Só serve para saber que Ganhou!!!
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'11111001'; //freq. aproximadamente ???hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10011011'; //freq. aproximadamente ???hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		for(i = 0; i < 1000; i++)
		{
			for(j = 0; j < 2000; j++)
			{
				TXREG = b'10001001'; //freq. aproximadamente ???hz
										//numeros do for pensados para tocar por aproximadamente 1s possivel de mudar apos testes!
			}
		}
		break;
	default:
		break;
   }
}

void AcendeLed(int nLed)//PELO NUMERO DO LED ELE ACENDE
{
	switch(nLed)
   {
	case 0:
			LED0 = 1;
		break;
	case 1:
			LED1 = 1;
		break:
	case 2:
			LED2 = 1;
		break;
	case 3:
			LED3 = 1;
		break;
	default:
		break;
   }
}

void ApagaLed(int nLed)//PELO NUMERO DO LED ELE APAGA
{
     switch(nLed)
   {
	case 0:
			LED0 = 0;
		break;
	case 1:
			LED1 = 0;
		break:
	case 2:
			LED2 = 0;
		break;
	case 3:
			LED3 = 0;
		break;
	default:
		break;
   }
}

void GeraPadrao(int padrao[])//CHAMA PARA GERAR UM PADRAO
{
	int i;
	for (i = 0; i < MAX_PADRAO; i++)
	{
		padrao[i] = rand() % 4;
	}
}

void ReproduzPadrao(int padrao[], int *nLevel)//EXECUTA O PADRAO GERADO
{
	 int i;
	 for (i = 0; i<*nLevel; i++)
	 {
		AcendeLed(padrao[i]);
		TocaBuzzer(padrao[i]);
		ApagaLed(padrao[i]);
		delay_ms(200); //CUIDADO COM A POSSIBILIDADE DE O BUZZER AINDA CONTINUAR TOCANDO
	 }
}

int LePadrao(int padrao[], int *nLevel)// 1 se padrao inserido for correto, caso contrário 0
{
	for (i = 0; i < *nLevel; i++)
	{
		if (padrao[i] != LeBotao())
			return 0;
	}
	*nLevel++;
	return 1;
}

int LeBotao()//retorna o numero do botao que for acionado, usada pela LePadrao
{
	  if(BT0 == 1)
		return 0;
	  else if (BT1 == 1)
		return 1;
	  else if (BT2 == 1)
		return 2;
	  else if (BT3 == 1)
		return 3;
	  delay_ms(2);
	  return LeBotao();
}

void main()
{
	Inicializa();

	int padrao[MAX_PADRAO];
	int padraoLido[MAX_PADRAO];
	int Level;
	int ganhouLevel;

	Level = 1;
	while(RESTART == 0)
	{
	}
	MCLRE = b'1';   //Seta o MasterClear.
	GerarPadrao(padrao[]);
	ganhouLevel = 1;
	while (ganhouLevel)
	{
		TocaBuzzer(4);
		delay_ms(20);
		ReproduzPadrao(padrao[], Level);
		ganhouLevel = LePadrao(padrao[], Level);
	}

	if (ganhouLevel==0) TocaBuzzer(5);  //Toca Buzina dos perdedores
	if (ganhouLevel)
	{
		TocaBuzzer(6);  //Toca buzina da vitória
		AcendeLed(0);
		delay_ms(50);
		AcendeLed(1);
		delay_ms(50);
		AcendeLed(2);
		delay_ms(50);
		AcendeLed(3);
	}
	//Para reinicializar, apenas aperte RESET
}

