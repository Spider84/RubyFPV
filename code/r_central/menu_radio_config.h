#pragma once
#include "menu_objects.h"
#include "popup.h"


class MenuRadioConfig: public Menu
{
   public:
      MenuRadioConfig();
      virtual ~MenuRadioConfig();
      virtual void Render();
      virtual void onShow();
      virtual void onMoveUp(bool bIgnoreReversion);
      virtual void onMoveDown(bool bIgnoreReversion);
      virtual void onMoveLeft(bool bIgnoreReversion);
      virtual void onMoveRight(bool bIgnoreReversion);
      virtual void onFocusedItemChanged();
      virtual void onItemValueChanged(int itemIndex);
      virtual void onItemEndEdit(int itemIndex);
      
      virtual int  onBack();
      virtual void onReturnFromChild(int returnValue);        
     
      virtual void onSelectItem();

   protected:
      void showProgressInfo();
      void hideProgressInfo();
      void setTooltipText();
      
      void onClickAutoTx(int iRadioLink);
      float computeHeights();
      void computeMaxItemIndex();

      float drawRadioLinks(float xStart, float xEnd);
      float drawRadioHeader(float xStart, float xEnd, float yStart);
      float drawRadioLink(float xStart, float xEnd, float yStart, int iRadioLink);
      float drawRadioInterfaceController(float xStart, float xEnd, float yStart, int iRadioLink, int iRadioInterface);

      float drawRadioInterfaceCtrlInfo(float xStart, float xEnd, float yStart, int iRadioLink, int iRadioInterface, bool bSelected);

      Popup* m_pPopupProgress;
      MenuItemSelect* m_pItemSelectTxCard;
      int m_iCurrentRadioLink;
      float m_fYPosAutoTx[MAX_RADIO_INTERFACES];
      float m_fYPosCtrlRadioInterfaces[MAX_RADIO_INTERFACES];
      float m_fYPosVehicleRadioInterfaces[MAX_RADIO_INTERFACES];
      float m_fYPosRadioLinks[MAX_RADIO_INTERFACES];
      float m_fFooterHeight;
      char m_szTooltip[256];
      bool m_bHas58PowerVehicle;
      bool m_bHas24PowerVehicle;
      bool m_bHasSiKPowerVehicle;
      bool m_bHas58PowerController;
      bool m_bHas24PowerController;
      bool m_bHasSiKPowerController;
      u32 m_uBandsSiKVehicle;
      u32 m_uBandsSiKController;
      int m_iCountVehicleRadioLinks;

      bool m_bHasSwapInterfacesCommand;

      bool m_bComputedHeights;

      int m_iIndexCurrentItem;
      int m_iIndexMaxItem;
      int m_iCountItemsTxPowerVehicle;
      int m_iCountItemsTxPowerController;
      int m_iHeaderItemsCount;

      float m_fHeightLinks[MAX_RADIO_INTERFACES];
      float m_fTotalHeightRadioConfig;

      bool m_bTmpHasVideoStreamsEnabled;
      bool m_bTmpHasDataStreamsEnabled;
};