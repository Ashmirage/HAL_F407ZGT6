#include "syn6288.h"
#include "usart.h"
#include "string.h"
#include "delay_us.h"

#define SYN6288_MAX_PAYLOAD   200u
#define SYN6288_FRAME_OVERHEAD 6u


//Music:ѡ�񱳾����֡�0:�ޱ������֣�1~15��ѡ�񱳾�����
void SYN_FrameInfo(u8 Music, u8 *HZdata)
{
  /****************��Ҫ���͵��ı�**********************************/
  unsigned  char  Frame_Info[SYN6288_MAX_PAYLOAD + SYN6288_FRAME_OVERHEAD];
  unsigned  short HZ_Length;
  unsigned  char  ecc  = 0;  			//����У���ֽ�
  unsigned  short i = 0;

  if(HZdata == 0)
  {
    return;
  }

  HZ_Length = strlen((char*)HZdata); 			//��Ҫ�����ı��ĳ���
  if((HZ_Length == 0) || (HZ_Length > SYN6288_MAX_PAYLOAD))
  {
    return;
  }

  /*****************֡�̶�������Ϣ**************************************/
  Frame_Info[0] = 0xFD ; 			//����֡ͷFD
  Frame_Info[1] = (unsigned char)(((HZ_Length + 3) >> 8) & 0xFF); //�������������ȵĸ��ֽ�
  Frame_Info[2] = (unsigned char)((HZ_Length + 3) & 0xFF); 		//�������������ȵĵ��ֽ�
  Frame_Info[3] = 0x01 ; 			//���������֣��ϳɲ�������
  Frame_Info[4] = 0x01 | ((Music & 0x0F) << 4) ; //����������������������趨

  /*******************У�������***************************************/
  for(i = 0; i < 5; i++)   				//���η��͹���õ�5��֡ͷ�ֽ�
  {
    ecc = ecc ^ (Frame_Info[i]);		//�Է��͵��ֽڽ������У��
  }

  for(i = 0; i < HZ_Length; i++)   		//���η��ʹ��ϳɵ��ı�����
  {
    ecc = ecc ^ (HZdata[i]); 				//�Է��͵��ֽڽ������У��
  }
  /*******************����֡��Ϣ***************************************/
  memcpy(&Frame_Info[5], HZdata, HZ_Length);
  Frame_Info[5 + HZ_Length] = ecc;
  HAL_UART_Transmit(&huart3, Frame_Info, HZ_Length + 6, 1000);
}


/***********************************************************
* ��    �ƣ� YS_SYN_Set(u8 *Info_data)
* ��    �ܣ� ������	�������
* ��ڲ����� *Info_data:�̶���������Ϣ����
* ���ڲ�����
* ˵    �����������������ã�ֹͣ�ϳɡ���ͣ�ϳɵ����� ��Ĭ�ϲ�����9600bps��
* ���÷�����ͨ�������Ѿ�������������������á�
**********************************************************/
void YS_SYN_Set(u8 *Info_data)
{
  u16 Com_Len;
  if(Info_data == 0)
  {
    return;
  }
  Com_Len = strlen((char*)Info_data);
  HAL_UART_Transmit(&huart3,Info_data, Com_Len,1000);
}

