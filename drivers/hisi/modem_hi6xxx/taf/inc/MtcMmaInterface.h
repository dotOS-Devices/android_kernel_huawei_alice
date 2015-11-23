/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : MtcMmaInterface.h
  �� �� ��   : ����
  ��    ��   : j00174725
  ��������   : 2013��08��13��
  ����޸�   :
  ��������   : MTC �� MMAģ�鹲��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��08��13��
    ��    ��   : j00174725
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef _MTCMMAINTERFACE_H_
#define _MTCMMAINTERFACE_H_

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"

/* Modified by z00161729 for DPLMN&NPLMN, 2014-11-4, begin */
#include "NasNvInterface.h"
/* Modified by z00161729 for DPLMN&NPLMN, 2014-11-4, end */

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
/* Modified by z00161729 for svlte support ncell search, 2013-12-24, begin */
#define MTC_MMA_MAX_EQUPLMN_NUM         (18)                                    /* ��Ч��PLMN�������� */
#define MTC_MMA_TDS_ARFCN_MAX_NUM       (9)                                     /* TDDƵ���б������� */
#define MTC_MMA_LTE_ARFCN_MAX_NUM       (8)                                     /* LTEƵ���б������� */
/* Modified by z00161729 for svlte support ncell search, 2013-12-24, end */

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
ö����    : MTC_MMA_MSG_ID_ENUM
�ṹ˵��  : MTCģ���MMAģ��֮�����Ϣ

  1.��    ��   : 2013��08��13��
    ��    ��   : ���±�/j00174725
    �޸�����   : V9R1 ���ſ�����Ŀ
  2.��    ��   : 2013��11��22��
    ��    ��   : z00161729
    �޸�����   : SVLTE�Ż�G-TL ps�л������޸�
  3.��    ��   : 2013��12��23��
    ��    ��   : z00161729
    �޸�����   : SVLTE֧��NCELL����
*****************************************************************************/
enum MTC_MMA_MSG_ID_ENUM
{
    /* ��Ϣ���� */                         /* ��ϢID */                         /* ��ע */
    /* MTC --> MMA */
    /* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-23, begin */
    ID_MTC_MMA_OTHER_MODEM_INFO_NOTIFY  = 0x0001,                               /* _H2ASN_MsgChoice MTC_MMA_OTHER_MODEM_INFO_NOTIFY_STRU */
    /* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-23, end */

    /* Modified by z00161729 for svlte support ncell search, 2013-12-23, begin */
    ID_MTC_MMA_NCELL_INFO_IND           = 0x0003,                               /* _H2ASN_MsgChoice MTC_MMA_NCELL_INFO_IND_STRU */
    /* Modified by z00161729 for svlte support ncell search, 2013-12-23, end */

    /* Modified by z00161729 for DTS2014010202583, 2014-1-7, begin */
    ID_MTC_MMA_PS_TRANSFER_IND          = 0x0005,                               /* _H2ASN_MsgChoice MTC_MMA_PS_TRANSFER_IND_STRU */
    /* Modified by z00161729 for DTS2014010202583, 2014-1-7, end */

    /* Modified by z00161729 for DPLMN&NPLMN, 2014-11-4, begin */
    ID_MTC_MMA_OTHER_MODEM_DPLMN_NPLMN_INFO_NOTIFY = 0x000b,                     /* _H2ASN_MsgChoice MTC_MMA_OTHER_MODEM_DPLMN_NPLMN_INFO_NOTIFY_STRU */
    /* Modified by z00161729 for DPLMN&NPLMN, 2014-11-4, end */


    /* MMA --> MTC */
    ID_MMA_MTC_POWER_STATE_IND          = 0x0002,                               /* _H2ASN_MsgChoice MMA_MTC_POWER_STATE_IND_STRU */
    ID_MMA_MTC_RAT_MODE_IND             = 0x0004,                               /* _H2ASN_MsgChoice MMA_MTC_RAT_MODE_IND_STRU */

    /* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-22, begin */
    ID_MMA_MTC_CURR_CAMP_PLMN_INFO_IND  = 0x0006,                               /* _H2ASN_MsgChoice MMA_MTC_CURR_CAMP_PLMN_INFO_IND_STRU */
    /* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-22, end */

    /* Modified by z00161729 for svlte support ncell search, 2013-12-24, begin */
    ID_MMA_MTC_EPLMN_INFO_IND           = 0x0008,                               /* _H2ASN_MsgChoice MMA_MTC_EPLMN_INFO_IND_STRU*/
    /* Modified by z00161729 for svlte support ncell search, 2013-12-24, end */

    /* Modified by z00161729 for DTS2014012305088, 2014-1-23, begin */
    ID_MMA_MTC_REG_STATUS_IND           = 0x000a,                               /* _H2ASN_MsgChoice MMA_MTC_REG_STATUS_IND_STRU */
    /* Modified by z00161729 for DTS2014012305088, 2014-1-23, end */

    /* Added by l00198894 for Volte Rank1, 2015-03-13, begin */
    ID_MMA_MTC_IMSA_STATE_IND           = 0x000c,                               /* _H2ASN_MsgChoice MMA_MTC_IMSA_STATE_IND_STRU */
    /* Added by l00198894 for Volte Rank1, 2015-03-13, end */


    ID_MMA_MTC_MSG_ID_BUTT
};
typedef VOS_UINT32  MTC_MMA_MSG_ID_ENUM_UINT32;

/*****************************************************************************
ö����    : MTC_MODEM_POWER_STATE_ENUM
�ṹ˵��  : MTCģ�鿪��״̬ö��

  1.��    ��   : 2013��08��13��
    ��    ��   : ���±�/j00174725
    �޸�����   : V9R1 ���ſ�����Ŀ
*****************************************************************************/
enum MTC_MODEM_POWER_STATE_ENUM
{
    MTC_MODEM_POWER_OFF                 = 0x00,
    MTC_MODEM_POWER_ON                  = 0x01,

    MTC_MODEM_POWER_STATE_BUTT
};
typedef VOS_UINT8  MTC_MODEM_POWER_STATE_ENUM_UINT8;

/*****************************************************************************
 ö����    : MTC_RATMODE_ENUM
 ö��˵��  : MMA֪ͨMTCģ�鵱ǰ�Ľ���ģʽ

  1.��    ��   : 2013��08��12��
    ��    ��   : l00198894
    �޸�����   : V9R1 ���ſ�����Ŀ
*****************************************************************************/
enum MTC_RATMODE_ENUM
{
    MTC_RATMODE_GSM                     = 0x00,
    MTC_RATMODE_WCDMA                   = 0x01,
    MTC_RATMODE_LTE                     = 0x02,
    MTC_RATMODE_TDS                     = 0x03,
    MTC_RATMODE_BUTT
};
typedef VOS_UINT8 MTC_RATMODE_ENUM_UINT8;

/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
/* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-23, begin */
/*****************************************************************************
 �ṹ��    : MTC_MMA_PLMN_ID_STRU
 �ṹ˵��  : plmn��Ϣ
 1.��    ��   : 2013��11��23��
   ��    ��   : z00161729
   �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulMcc;
    VOS_UINT32                          ulMnc;
} MTC_MMA_PLMN_ID_STRU;

/* Modified by z00161729 for svlte support ncell search, 2013-12-24, begin */
/*****************************************************************************
 �ṹ��    : MTC_MMA_EPLMN_INFO_STRU
 �ṹ˵��  : ��Чplmn��Ϣ
 1.��    ��   : 2013��12��23��
   ��    ��   : z00161729
   �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucEquPlmnNum;                           /* ��ǰEquPLMN�ĸ��� */
    VOS_UINT8                           aucReserved[3];
    MTC_MMA_PLMN_ID_STRU                astEquPlmnAddr[MTC_MMA_MAX_EQUPLMN_NUM];/* ��ǰEquPLMN�б� */
}MTC_MMA_EPLMN_INFO_STRU;

/* Modified by z00161729 for svlte support ncell search, 2013-12-24, end */

/*****************************************************************************
 �ṹ��    : MTC_MMA_OTHER_MODEM_INFO_NOTIFY_STRU
 �ṹ˵��  : modem1����ϢĿǰֻ��פ����Ϣ
 1.��    ��   : 2013��11��23��
   ��    ��   : z00161729
   �޸�����   : �½�
 2.��    ��   : 2013��12��24��
   ��    ��   : z00161729
   �޸�����   : SVLTE֧��NCELL����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU              stMsgHeader;                                   /*_H2ASN_Skip*/
    VOS_UINT32                   bitOpCurrCampPlmnId:1;

    /* Modified by z00161729 for svlte support ncell search, 2013-12-24, begin */
    VOS_UINT32                   bitOpEplmnInfo:1;
    VOS_UINT32                   bitSpare:30;
    /* Modified by z00161729 for svlte support ncell search, 2013-12-24, end */

    MTC_MMA_PLMN_ID_STRU         stCurrCampPlmnId;                              /* ������д��ǰפ��С����PLMN������������߹ػ��ȷ�פ��״̬��ͳһ��дȫ0xff */

    /* Modified by z00161729 for svlte support ncell search, 2013-12-24, begin */
    MTC_MMA_EPLMN_INFO_STRU      stEplmnInfo;
    /* Modified by z00161729 for svlte support ncell search, 2013-12-24, end */

} MTC_MMA_OTHER_MODEM_INFO_NOTIFY_STRU;

/* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-23, end */

/* Modified by z00161729 for DPLMN&NPLMN, 2014-11-4, begin */
/*****************************************************************************
 �ṹ��    : MTC_MMA_OTHER_MODEM_DPLMN_NPLMN_INFO_NOTIFY_STRU
 �ṹ˵��  : modem1��dplmn��nplmn��Ϣ
 1.��    ��   : 2014��11��3��
   ��    ��   : z00161729
   �޸�����   : ��������������Ŀ�޸�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                                        stMsgHeader;                                   /*_H2ASN_Skip*/

    NAS_MMC_NVIM_CFG_DPLMN_NPLMN_INFO_STRU                 stCmccDplmnNplmnInfo;
    NAS_MMC_NVIM_CFG_DPLMN_NPLMN_INFO_STRU                 stUnicomDplmnNplmnInfo;
    NAS_MMC_NVIM_CFG_DPLMN_NPLMN_INFO_STRU                 stCtDplmnNplmnInfo;
}MTC_MMA_OTHER_MODEM_DPLMN_NPLMN_INFO_NOTIFY_STRU;

/* Modified by z00161729 for DPLMN&NPLMN, 2014-11-4, end */

/* Modified by z00161729 for DTS2014010202583, 2014-1-7, begin */
/*******************************************************************************
�ṹ��    : MTC_MMA_PS_TRANSFER_IND_STRU
�ṹ˵��  : ID_MTC_MMA_PS_TRANSFER_IND_STRU����Ϣ�ṹ
1.��    ��   : 2014��1��5��
  ��    ��   : z00161729
  �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           enSolutionCfg;                          /* PS��Ǩ�Ʒ��� */
    VOS_UINT8                           ucCause;                                /* PS���л�ԭ��ֵ */
    VOS_UINT8                           aucReserved[2];                         /*����λ*/
} MTC_MMA_PS_TRANSFER_IND_STRU;

/* Modified by z00161729 for DTS2014010202583, 2014-1-7, end */

/*******************************************************************************
 �ṹ��    : MMA_MTC_POWER_STATE_IND_STRU
 �ṹ˵��  : ID_MMA_MTC_POWER_STATE_IND����Ϣ�ṹ

 1.��    ��   : 2013��08��12��
   ��    ��   : ���±�/j00174725
   �޸�����   : ������
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTC_MODEM_POWER_STATE_ENUM_UINT8    enPowerState;                           /* ��ǰ���ػ�״̬ */
    VOS_UINT8                           aucReserved[3];
} MMA_MTC_POWER_STATE_IND_STRU;

/*******************************************************************************
 �ṹ��    : MMA_MTC_IMSA_STATE_IND_STRU
 �ṹ˵��  : ID_MMA_MTC_POWER_STATE_IND����Ϣ�ṹ

 1.��    ��   : 2015��03��13��
   ��    ��   : l00198894
   �޸�����   : VOLTE Randk1������Ŀ
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTC_MODEM_POWER_STATE_ENUM_UINT8    enPowerState;                           /* IMSA���ػ�״̬ */
    VOS_UINT8                           aucReserved[3];
} MMA_MTC_IMSA_STATE_IND_STRU;

/*******************************************************************************
 �ṹ��    : MMA_MTC_RAT_MODE_IND_STRU
 �ṹ˵��  : ID_MMA_MTC_RAT_MODE_IND����Ϣ�ṹ

 1.��    ��   : 2013��08��12��
   ��    ��   : l00198894
   �޸�����   : ������
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTC_RATMODE_ENUM_UINT8              enRatMode;                              /* ��ǰ����ģʽ */
    VOS_UINT8                           aucReserved[3];
} MMA_MTC_RAT_MODE_IND_STRU;


/* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-22, begin */
/*******************************************************************************
 �ṹ��    : MMA_MTC_CURR_CAMP_PLMN_INFO_IND_STRU
 �ṹ˵��  : MMA_MTC_CURR_CAMP_PLMN_INFO_IND����Ϣ�ṹ

 1.��    ��   : 2013��11��22��
   ��    ��   : z00161729
   �޸�����   : ������
 2.��    ��   : 2014��01��17��
   ��    ��   : l00198894
   �޸�����   : V9R1C53 C+L ������ѡ��Ŀ
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTC_MMA_PLMN_ID_STRU                stPlmnId;                               /* ��ǰפ������ */
    MTC_RATMODE_ENUM_UINT8              enRatMode;                              /* ��ǰ����ģʽ */
    VOS_UINT8                           ucIsForbiddenPlmnFlag;                  /* ��ǰפ�������Ƿ�Ϊ��ֹ�����ʶ */
    VOS_UINT8                           ucPsAttachAllowFlag;
    /* Modified by l00198894 for V9R1 C+L PsTransfer, 2014-01-17, begin */
    VOS_UINT8                           ucPsSupportFlg;                         /* ��ǰ�����Ƿ�֧��PS�� */
    /* Modified by l00198894 for V9R1 C+L PsTransfer, 2014-01-17, end */
} MMA_MTC_CURR_CAMP_PLMN_INFO_IND_STRU;
/* Modified by z00161729 for svlte g-tl ps transfer optimize, 2013-11-22, end */

/* Modified by z00161729 for svlte support ncell search, 2013-12-23, begin */
/*******************************************************************************
 �ṹ��    : MTC_MMA_TDS_NCELL_INFO_STRU
 �ṹ˵��  : GSM�µ�TDSƵ���б�

 1.��    ��   : 2013��12��24��
   ��    ��   : z00161729
   �޸�����   : SVLTE֧��NCELL����

*******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucTdsArfcnNum;                          /* 0��ʾTDDƵ�㲻���� */
    VOS_UINT8                           ucReserved;
    VOS_UINT16                          ausTdsArfcnList[MTC_MMA_TDS_ARFCN_MAX_NUM];
}MTC_MMA_TDS_NCELL_INFO_STRU;

/*******************************************************************************
 �ṹ��    : MTC_MMA_LTE_NCELL_INFO_STRU
 �ṹ˵��  : GSM�µ�LTEƵ���б�

 1.��    ��   : 2013��12��24��
   ��    ��   : z00161729
   �޸�����   : SVLTE֧��NCELL����

*******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucLteArfcnNum;                          /* 0��ʾLTEƵ�㲻���� */
    VOS_UINT8                           aucReserved[3];
    VOS_UINT16                          ausLteArfcnList[MTC_MMA_LTE_ARFCN_MAX_NUM];
}MTC_MMA_LTE_NCELL_INFO_STRU;


/*******************************************************************************
 �ṹ��    : MTC_MMA_TDS_LTE_NCELL_INFO_IND_STRU
 �ṹ˵��  : ID_MTC_MMA_TDD_LTE_NCELL_INFO_IND��Ϣ��Ӧ�Ľṹ��
             ����GSM�µ�TDS/LTE�����ṹ�е�TDS/LTE��Ƶ���б�

 1.��    ��   : 2013��12��23��
   ��    ��   : z00161729
   �޸�����   : �����ɽṹ

*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTC_MMA_TDS_NCELL_INFO_STRU         stTdsNcellInfo;
    MTC_MMA_LTE_NCELL_INFO_STRU         stLteNcellInfo;
}MTC_MMA_NCELL_INFO_IND_STRU;


/*****************************************************************************
 �ṹ��    : MMA_MTC_EPLMN_INFO_IND_STRU
 �ṹ˵��  : ��Чplmn��Ϣ
 1.��    ��   : 2013��12��23��
   ��    ��   : z00161729
   �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTC_MMA_EPLMN_INFO_STRU             stEplmnInfo;
}MMA_MTC_EPLMN_INFO_IND_STRU;

/* Modified by z00161729 for svlte support ncell search, 2013-12-23, end */
/* Modified by z00161729 for DTS2014012305088, 2014-1-23, begin */
/*******************************************************************************
 �ṹ��    : MMA_MTC_REG_STATUS_IND_STRU
 �ṹ˵��  : MMA_MTC_REG_STATUS_IND_STRU����Ϣ�ṹ

 1.��    ��   : 2014��1��23��
   ��    ��   : z00161729
   �޸�����   : DTS2014012305088:svlte���Կ�������Ч����mtc�����ϱ�pstransfer:0

*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           ucIsUsimValidFlg;                       /* ��ʶ���Ƿ���Ч��1:��Ч��0:��Ч*/
    VOS_UINT8                           aucReserved[3];
} MMA_MTC_REG_STATUS_IND_STRU;

/* Modified by z00161729 for DTS2014012305088, 2014-1-23, end */
/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/

/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    MTC_MMA_MSG_ID_ENUM_UINT32          enMsgID;                                /*_H2ASN_MsgChoice_Export MTC_MMA_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MTC_MMA_MSG_ID_ENUM_UINT32
    ****************************************************************************/
} MTC_MMA_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MTC_MMA_MSG_DATA                    stMsgData;
} MtcMmaInterface_MSG;

/*****************************************************************************
  10 ��������
*****************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MtcMmaInterface.h */
