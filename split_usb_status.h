//---------------------------------------------------------------------------

#pragma once
#include "javelin/usb_status.h"
#include "split_tx_rx.h"
#include <stdint.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

#if JAVELIN_SPLIT

class SplitUsbStatus final : public SplitTxHandler, public SplitRxHandler {
public:
  void OnMount();
  void OnUnmount();
  void OnSuspend();
  void OnResume();

  static void RegisterTxHandler() { SplitTxRx::RegisterTxHandler(&instance); }

  static void RegisterRxHandler() {
    SplitTxRx::RegisterRxHandler(SplitHandlerId::USB_STATUS, &instance);
  }

  static SplitUsbStatus instance;

private:
  bool dirty;
  UsbStatus status;

  virtual void UpdateBuffer(TxBuffer &buffer);
  virtual void OnTransmitConnectionReset() { dirty = true; }
  virtual void OnDataReceived(const void *data, size_t length);

  void UpdateUsbStatusInstance();
};

#else

class SplitUsbStatus : public UsbStatus {
public:
  static void RegisterTxHandler() {}
  static void RegisterRxHandler() {}
};

#endif // JAVELIN_SPLIT

//---------------------------------------------------------------------------
