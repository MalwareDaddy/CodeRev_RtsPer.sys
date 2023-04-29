//MmIoSpace Start : _Src_RtsPer.sys\FUN_1400a1b4c@1400a1b4c.c

void entry(longlong param_1)

{
  FUN_1400f202c();
  DriverEntry(param_1);
  return;
}


//-------------------------------------------------------------------------------------------//
//File : FUN_1400a04c8@1400a04c8.c


void DriverEntry(longlong param_1)
// param_1 == Driver Object
{
  int iVar1;
  undefined auStack360 [32];
  char *local_148;
  undefined4 local_138;
  uint local_134;
  uint local_130;
  ulonglong local_18;
  
  local_18 = DAT_1400e8d58 ^ (ulonglong)auStack360;
  local_148 = "09:59:20";
  DbgPrint(2,"%s : -> DriverEntry built on %s at %s \n","DriverEntry",(ulonglong)"Apr 24 2019")
  ;
  DbgPrint(2,"%s : -> DriverEntry Driver version : %s \n","DriverEntry",
                (ulonglong)"10.0.18362.21317");
  local_138 = 0x114;
  iVar1 = RtlGetVersion(&local_138);
  if ((-1 < iVar1) && ((6 < local_134 || ((local_134 == 6 && (1 < local_130)))))) {
    DAT_1400e8d80 = 0x200;
    DAT_1400e8d84 = 0x40000000;
  }
  FUN_14000ef2c();
  *(code **)(param_1 + 0xe0) = FUN_140002690;
  *(code **)(param_1 + 0x120) = FUN_1400a9a40;
  *(code **)(param_1 + 0x148) = FUN_1400a37d0; // Hex : 0x148  Dec : 328 
  *(code **)(param_1 + 0x70) = FUN_140002520;
  *(code **)(param_1 + 0x80) = FUN_140002450;
  *(code **)(param_1 + 0x100) = FUN_140002190;
  *(code **)(param_1 + 0xf0) = FUN_1400055f0;
  *(code **)(param_1 + 0x128) = FUN_1400b7e70;
  *(code **)(param_1 + 0x90) = FUN_1400045e0;
  *(code **)(param_1 + 0x88) = FUN_1400045e0;
  *(code **)(param_1 + 0xe8) = FUN_140003940;
  *(code **)(param_1 + 0x68) = FUN_1400a1200;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = FUN_1400a0670;
  FUN_1400011e4();
  FUN_1400a0390();
  FUN_1400a0fac();
  local_148 = (char *)((ulonglong)local_148 & 0xffffffff00000000);
  DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","DriverEntry",(ulonglong)"DriverEntry");
  __security_check_cookie(local_18 ^ (ulonglong)auStack360);
  return;
}
//-------------------------------------------------------------------------------------------//
//File : FUN_1400a37d0@1400a37d0.c


ulonglong FUN_1400a37d0(longlong param_1,longlong param_2)

// param_1 is a Driver Object , param_2 : Hex : 0x148  Dec : 328
{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  ushort *puVar5;
  byte bVar6;
  undefined4 uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 uVar11;
  char *pcVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  char *pcVar16;
  char *pcVar17;
  bool bVar18;
  ulonglong uVar15;
  
  if (**(char **)(param_1 + 0x40) != '\x01') {
    lVar3 = *(longlong *)(param_1 + 0x40);
    uVar15 = 0;
    uVar14 = 0;
    lVar10 = *(longlong *)(param_2 + 0xb8);
    lVar4 = *(longlong *)(lVar3 + 8);
    uVar13 = uVar15;
    if (lVar4 != 0) {
      uVar13 = *(ulonglong *)(lVar4 + 0x40);
    }
    pcVar17 = "DispatchPnP_Pdo ";
    pcVar12 = "%s : -> %s %s %s \n";
    DbgPrint(0x20,"%s : -> %s %s %s \n","rts_pnp_pdo",(ulonglong)"DispatchPnP_Pdo ");
    if ((lVar4 == 0) || (uVar13 == 0)) {
      if (*(char *)(lVar10 + 1) == '\x02') {
        IoDeleteDevice(param_1);
        *(undefined4 *)(param_2 + 0x30) = 0;
        IofCompleteRequest(param_2,0);
        DbgPrint(0x20,"%s : NULL == Fdo , is IRP_MN_REMOVE_DEVICE,delete Pdo \n","rts_pnp_pdo",
                      (ulonglong)pcVar17);
        DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pnp_pdo",(ulonglong)"rts_pnp_pdo");
        return 0;
      }
      pcVar12 = 
      "%s : NULL == Fdo, not IRP_MN_REMOVE_DEVICE,so return fail with STATUS_DELETE_PENDING\n";
LAB_1400a5a7e:
      DbgPrint(0x20,pcVar12,"rts_pnp_pdo",(ulonglong)pcVar17);
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
      IofCompleteRequest(param_2,0);
      DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pnp_pdo",(ulonglong)"rts_pnp_pdo");
      return 0xc0000056;
    }
    if (*(int *)(uVar13 + 0x24) == 7) {
      pcVar12 = "%s : Removed == fdx->DeviceState, so quit \n";
      goto LAB_1400a5a7e;
    }
    uVar9 = FUN_1400acccc(uVar13);
    if ((char)uVar9 != '\0') {
      pcVar16 = "rts_pnp_pdo";
      DbgPrint(0x20,"%s : call rts_ss_cancel_ss \n","rts_pnp_pdo",(ulonglong)pcVar17);
      pcVar12 = (char *)0x0;
      FUN_1400acf1c(uVar13,0,pcVar16,(ulonglong)pcVar17);
    }
    bVar6 = *(byte *)(lVar10 + 1);
    if (bVar6 < 8) {
      if (bVar6 != 7) {
        if (bVar6 == 0) {
          KeAcquireSpinLockRaiseToDpc(lVar3 + 0x30);
          *(undefined4 *)(lVar3 + 0x28) = *(undefined4 *)(lVar3 + 0x24);
          *(undefined4 *)(lVar3 + 0x24) = 2;
          KeReleaseSpinLock(lVar3 + 0x30);
          FUN_14001beac(lVar3);
          FUN_1400a3410(param_1,'\x03');
          if (*(char *)(*(longlong *)(uVar13 + 1000) + 0x192) != '\0') {
            *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1;
          }
          goto LAB_1400a59f7;
        }
        if (bVar6 == 1) {
          bVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x30);
          uVar13 = (ulonglong)pcVar12 & 0xffffffffffffff00 | (ulonglong)bVar6;
          uVar7 = *(undefined4 *)(lVar3 + 0x24);
          *(undefined4 *)(lVar3 + 0x24) = 4;
          goto LAB_1400a578c;
        }
        if (bVar6 == 2) {
          FUN_1400a651c(param_1);
          goto LAB_1400a59f7;
        }
        if (bVar6 == 3) {
          bVar18 = *(int *)(lVar3 + 0x24) == 4;
LAB_1400a574c:
          uVar14 = uVar15;
          if (!bVar18) goto LAB_1400a59f7;
          bVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x30);
          uVar13 = (ulonglong)pcVar12 & 0xffffffffffffff00 | (ulonglong)bVar6;
          *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(lVar3 + 0x28);
        }
        else {
          if (bVar6 == 4) {
            bVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x30);
            uVar13 = (ulonglong)pcVar12 & 0xffffffffffffff00 | (ulonglong)bVar6;
            uVar7 = *(undefined4 *)(lVar3 + 0x24);
            *(undefined4 *)(lVar3 + 0x24) = 1;
          }
          else {
            if (bVar6 != 5) {
              if (bVar6 != 6) goto LAB_1400a5909;
              bVar18 = *(int *)(lVar3 + 0x24) == 3;
              goto LAB_1400a574c;
            }
            bVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x30);
            uVar13 = (ulonglong)pcVar12 & 0xffffffffffffff00 | (ulonglong)bVar6;
            uVar7 = *(undefined4 *)(lVar3 + 0x24);
            *(undefined4 *)(lVar3 + 0x24) = 3;
          }
LAB_1400a578c:
          *(undefined4 *)(lVar3 + 0x28) = uVar7;
        }
        KeReleaseSpinLock(lVar3 + 0x30,uVar13);
        uVar14 = uVar15;
        goto LAB_1400a59f7;
      }
      iVar2 = *(int *)(lVar10 + 8);
      if (iVar2 == 0) {
        DbgPrint(0x20,"%s : BusRelations \n","rts_pnp_pdo",(ulonglong)pcVar17);
        lVar10 = FUN_14000ee90(lVar3);
        if ((char)lVar10 != '\0') {
          FUN_14000edf4(uVar13);
          FUN_14001c37c(lVar3);
          FUN_14001bab8(uVar13);
        }
      }
      else {
        if (iVar2 == 1) {
          pcVar12 = "%s : EjectionRelations \n";
        }
        else if (iVar2 == 2) {
          pcVar12 = "%s : PowerRelations \n";
        }
        else {
          if (iVar2 != 3) {
            if (iVar2 == 4) {
              DbgPrint(0x20,"%s : TargetDeviceRelation \n","rts_pnp_pdo",(ulonglong)pcVar17);
              lVar10 = FUN_14000ee90(lVar3);
              if ((char)lVar10 != '\0') {
                FUN_14000edf4(uVar13);
                FUN_14001c37c(lVar3);
                FUN_14001bab8(uVar13);
                if ((*(longlong *)(uVar13 + 0x598) != 0) &&
                   (*(int *)(*(longlong *)(uVar13 + 0x598) + 0x300) != 0)) {
                  *(undefined *)(lVar3 + 0x50) = 1;
                }
                FUN_14001beac(lVar3);
              }
            }
            goto LAB_1400a58d0;
          }
          pcVar12 = "%s : RemovalRelations \n";
        }
        DbgPrint(0x20,pcVar12,"rts_pnp_pdo",(ulonglong)pcVar17);
      }
LAB_1400a58d0:
      uVar8 = FUN_1400a5b8c(param_1,param_2);
    }
    else {
      if (bVar6 == 9) {
        puVar5 = *(ushort **)(lVar10 + 8);
        if ((puVar5[1] == 1) && (0x3f < *puVar5)) {
          uVar8 = (uint)*(byte *)(*(longlong *)(uVar13 + 1000) + 0xe4);
          *(undefined4 *)(puVar5 + 6) = 0;
          uVar8 = (uVar8 & 0x20 | 4) << 4 | uVar8 & 0x10 | *(uint *)(puVar5 + 2) & 0xfffffdef;
          *(uint *)(puVar5 + 2) = uVar8;
          uVar14 = uVar15;
          if (*(char *)(*(longlong *)(uVar13 + 1000) + 2) == '\0') {
            uVar8 = uVar8 | 0x10008;
            *(uint *)(puVar5 + 2) = uVar8;
          }
        }
        else {
          uVar8 = *(uint *)(puVar5 + 2);
          uVar14 = 0xc0000001;
        }
        DbgPrint(0x20,
                      "%s : deviceCapabilities->Removable is %i,deviceCapabilities->SurpriseRemovalOK is %i,deviceCapabilities->UniqueID is %i, ntStatus is 0x%x \n"
                      ,"rts_pnp_pdo",(ulonglong)(uVar8 >> 4 & 1));
        goto LAB_1400a59f7;
      }
      if (bVar6 == 0xc) {
        uVar8 = FUN_1400a5d04(param_1,param_2);
      }
      else if (bVar6 == 0x13) {
        uVar8 = FUN_1400a5e34(param_1,param_2);
      }
      else {
        if (bVar6 == 0x14) goto LAB_1400a59f7;
        if (bVar6 != 0x15) {
          if (bVar6 == 0x16) {
            uVar14 = 0xc0000001;
            goto LAB_1400a59f7;
          }
          if (bVar6 == 0x17) {
            FUN_1400a6918(param_1);
            goto LAB_1400a59f7;
          }
LAB_1400a5909:
          uVar14 = (ulonglong)*(uint *)(param_2 + 0x30);
          goto LAB_1400a59f7;
        }
        uVar8 = FUN_1400a5ae0(param_1,param_2);
      }
    }
    uVar14 = (ulonglong)uVar8;
LAB_1400a59f7:
    *(int *)(param_2 + 0x30) = (int)uVar14;
    IofCompleteRequest(param_2,0);
    DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pnp_pdo",(ulonglong)"rts_pnp_pdo");
    return uVar14;
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar10 = *(longlong *)(param_1 + 0x40);
  if (*(byte *)(lVar3 + 1) < 0x19) {
    pcVar12 = (&PTR_s_IRP_MN_START_DEVICE_1400e8810)[*(byte *)(lVar3 + 1)];
  }
  else {
    pcVar12 = "UNKNOW";
  }
  DbgPrint(2,"%s : -> %s %s %s \n","rts_pnp_fdo",(ulonglong)"DispatchPnP_Fdo ");
  uVar13 = (ulonglong)*(uint *)(lVar10 + 0x24);
  DbgPrint(0x20,"%s : rts_pnp_fdo: fdx DeviceState %i \n","rts_pnp_fdo",uVar13);
  cVar1 = *(char *)(lVar3 + 1);
  if ((cVar1 != '\a') || (*(longlong *)(lVar10 + 0x590) != 0)) {
    if ((*(int *)(lVar10 + 0x24) != 7) && ((cVar1 != '\x02' || (*(int *)(lVar10 + 0x24) != 0)))) {
      if ((cVar1 != '\0') &&
         ((cVar1 != '\t' && (uVar14 = FUN_1400acccc(lVar10), (char)uVar14 != '\0')))) {
        pcVar17 = "rts_pnp_fdo";
        DbgPrint(0x20,"%s : call rts_ss_cancel_ss \n","rts_pnp_fdo",uVar13);
        FUN_1400acf1c(lVar10,0,pcVar17,uVar13);
      }
      if (((*(byte *)(lVar3 + 1) < 0x18) && ((0x800094U >> (*(byte *)(lVar3 + 1) & 0x1f) & 1) != 0))
         && (*(longlong *)(lVar10 + 0x590) != 0)) {
        FUN_14001bacc(lVar10);
        uVar13 = 0;
        KeWaitForSingleObject(lVar10 + 0x1a0,0,0,0,0,pcVar12);
      }
      FUN_140005bb0(lVar10);
      bVar6 = *(byte *)(lVar3 + 1);
      if (bVar6 < 6) {
        if (bVar6 == 5) {
          if (*(int *)(lVar10 + 0x20) == 0) {
            bVar6 = KeAcquireSpinLockRaiseToDpc(lVar10 + 0x30);
            uVar8 = *(uint *)(lVar10 + 0x24);
            *(undefined4 *)(lVar10 + 0x24) = 3;
            goto LAB_1400a39b3;
          }
LAB_1400a3a31:
          uVar8 = 0xc0000001;
        }
        else {
          if (bVar6 != 0) {
            if (bVar6 != 1) {
              if (bVar6 == 2) {
                uVar8 = FUN_1400a4888(param_1,param_2);
                goto LAB_1400a3b2f;
              }
              if (bVar6 == 3) {
                uVar8 = FUN_1400a3b68(param_1,param_2);
              }
              else {
                if (bVar6 != 4) goto LAB_1400a3a72;
                uVar8 = FUN_1400a50cc(param_1,param_2);
              }
              goto LAB_1400a3969;
            }
            if (*(int *)(lVar10 + 0x20) != 0) goto LAB_1400a3a31;
            bVar6 = KeAcquireSpinLockRaiseToDpc(lVar10 + 0x30);
            uVar8 = *(uint *)(lVar10 + 0x24);
            *(undefined4 *)(lVar10 + 0x24) = 4;
LAB_1400a39b3:
            *(uint *)(lVar10 + 0x28) = uVar8;
            KeReleaseSpinLock(lVar10 + 0x30,uVar8 & 0xffffff00 | (uint)bVar6);
            *(undefined4 *)(param_2 + 0x30) = 0;
            *(undefined8 *)(param_2 + 0x38) = 0;
LAB_1400a39ca:
            *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
            *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
            uVar8 = IofCallDriver(*(undefined8 *)(lVar10 + 0x10),param_2);
            goto LAB_1400a3969;
          }
          if (DAT_1400e8ec0 == '\0') {
            FUN_14001b9b8(L"RSPER");
            DAT_1400e8ec0 = '\x01';
          }
          uVar11 = FUN_1400a4c7c(param_1,param_2);
          uVar8 = (uint)uVar11;
          if (uVar8 == 0x103) goto LAB_1400a3b2f;
        }
LAB_1400a3a18:
        *(uint *)(param_2 + 0x30) = uVar8;
        IofCompleteRequest(param_2,0);
      }
      else {
        if (bVar6 == 6) {
          uVar8 = FUN_1400a3c54(param_1,param_2);
          goto LAB_1400a3969;
        }
        if (bVar6 == 7) {
          uVar8 = FUN_1400a4724(param_1,param_2);
          goto LAB_1400a3b2f;
        }
        if (bVar6 == 9) {
          uVar8 = FUN_1400a4430(param_1,param_2);
          goto LAB_1400a3a18;
        }
        if (bVar6 == 0xd) {
          if ((*(char *)(*(longlong *)(lVar10 + 1000) + 0x13e) == '\0') ||
             (5 < *(int *)(lVar10 + 0x1d8))) {
            pcVar12 = "%s : MSI not enable,IRP_MN_FILTER_RESOURCE_REQUIREMENTS to default\n";
            uVar11 = 0x20;
LAB_1400a3a7e:
            DbgPrint(uVar11,pcVar12,"rts_pnp_fdo",uVar13);
            goto LAB_1400a39ca;
          }
          uVar8 = FUN_1400a3d40(param_1,param_2);
        }
        else {
          if (bVar6 != 0x17) {
LAB_1400a3a72:
            pcVar12 = "%s : Unprocessed pnp,to default process \n";
            uVar11 = 1;
            goto LAB_1400a3a7e;
          }
          uVar8 = FUN_1400a52ac(param_1,param_2);
        }
      }
LAB_1400a3969:
      FUN_140005af8(lVar10);
      goto LAB_1400a3b2f;
    }
    DbgPrint(0x20,"%s : Removed == fdx->DeviceState\n","rts_pnp_fdo",uVar13);
  }
  uVar8 = 0xc0000056;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
  IofCompleteRequest(param_2,0);
LAB_1400a3b2f:
  DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pnp_fdo",(ulonglong)"rts_pnp_fdo");
  return (ulonglong)uVar8;
}
//-------------------------------------------------------------------------------------------//
//File : FUN_1400a4c7c@1400a4c7c.c


undefined8 FUN_1400a4c7c(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 *puVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  DbgPrint(0x2000,"%s : -> %s\n","rts_pnp_fdo_start_dev",(ulonglong)"rts_pnp_fdo_start_dev");
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  puVar3 = *(undefined4 **)(param_2 + 0xb8);
  puVar3[-0x12] = *puVar3;
  puVar3[-0x11] = puVar3[1];
  puVar3[-0x10] = puVar3[2];
  puVar3[-0xf] = puVar3[3];
  puVar3[-0xe] = puVar3[4];
  puVar3[-0xd] = puVar3[5];
  puVar3[-0xc] = puVar3[6];
  puVar3[-0xb] = puVar3[7];
  puVar3[-10] = puVar3[8];
  puVar3[-9] = puVar3[9];
  puVar3[-8] = puVar3[10];
  puVar3[-7] = puVar3[0xb];
  *(undefined8 *)(puVar3 + -6) = *(undefined8 *)(puVar3 + 0xc);
  *(undefined *)((longlong)puVar3 + -0x45) = 0;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar4 + -0x10) = FUN_1400a4b70;
  *(longlong *)(lVar4 + -8) = lVar2;
  *(undefined *)(lVar4 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
  DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pnp_fdo_start_dev",
                (ulonglong)"rts_pnp_fdo_start_dev");
  return 0x103;
}
//-------------------------------------------------------------------------------------------//
//File : FUN_1400a4b70@1400a4b70.c


undefined8 FUN_1400a4b70(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)*(uint *)(param_2 + 0x30);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((int)*(uint *)(param_2 + 0x30) < 0) {
    DbgPrint(1,"%s : In rts_pnp_fdo_start_completion,irp fail with 0x%x,finish it \n",
                  "rts_pnp_fdo_start_completion",uVar4);
  }
  else {
    plVar2 = (longlong *)ExAllocatePoolWithTag(DAT_1400e8d80,0x20,0x30395349);
    if (plVar2 == (longlong *)0x0) {
      *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
      DbgPrint(1,"%s : In rts_pnp_fdo_start_completion, allocate context fail,finish it \n",
                    "rts_pnp_fdo_start_completion",uVar4);
    }
    else {
      lVar3 = IoAllocateWorkItem(*(undefined8 *)(lVar1 + 8));
      if (lVar3 != 0) {
        plVar2[3] = 0;
        *plVar2 = lVar3;
        plVar2[2] = param_2;
        IoQueueWorkItem(lVar3,FUN_1400a4d40,1,plVar2);
        return 0xc0000016;
      }
      *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
      DbgPrint(1,"%s : In rts_pnp_fdo_start_completion IoAllocateWorkItem fail, finish it\n",
                    "rts_pnp_fdo_start_completion",uVar4);
      ExFreePoolWithTag(plVar2,0);
    }
  }
  FUN_140005af8(lVar1);
  KeSetEvent(lVar1 + 0x1a0,0,0);
  return 0;
}
//-------------------------------------------------------------------------------------------//
//File : FUN_1400a4d40@1400a4d40.c


void FUN_1400a4d40(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  char *pcVar5;
  ulonglong uVar6;
  char cVar7;
  char *pcVar8;
  char *pcVar9;
  longlong lVar10;
  
  uVar1 = *(ulonglong *)(param_1 + 0x40);
  pcVar9 = "rts_pnp_fdo_start_dev_delaywork";
  pcVar2 = (char *)param_2[2];
  DbgPrint(0x2000,"%s : -> %s\n","rts_pnp_fdo_start_dev_delaywork",
                (ulonglong)"rts_pnp_fdo_start_dev_delaywork");
  bVar3 = KeAcquireSpinLockRaiseToDpc(uVar1 + 0x30);
  uVar4 = *(uint *)(uVar1 + 0x24);
  *(uint *)(uVar1 + 0x28) = uVar4;
  *(undefined4 *)(uVar1 + 0x24) = 2;
  KeReleaseSpinLock(uVar1 + 0x30,uVar4 & 0xffffff00 | (uint)bVar3);
  pcVar8 = (char *)0x1;
  *(undefined4 *)(uVar1 + 0xf0) = 1;
  *(undefined4 *)(uVar1 + 0xec) = 1;
  PoSetPowerState(*(undefined8 *)(uVar1 + 8),1);
  *(undefined4 *)(uVar1 + 0xa60) = 0xff;
  *(undefined4 *)(uVar1 + 0xa5c) = 0xff;
  pcVar5 = pcVar2;
  uVar4 = thunk_FUN_1400b5c0c(uVar1,(longlong)pcVar2);
  if (uVar4 == 0) {
    uVar4 = FUN_1400b1788(uVar1);
    if (-1 < (int)uVar4) {
      uVar4 = FUN_1400b183c(uVar1);
      if (-1 < (int)uVar4) {
        uVar4 = FUN_1400b1558(uVar1);
        if (-1 < (int)uVar4) {
          uVar4 = FUN_1400b16d4(uVar1);
          if (-1 < (int)uVar4) {
            if (*(char *)(*(longlong *)(uVar1 + 1000) + 0x19f) != '\0') {
              uVar4 = FUN_1400b1620(uVar1);
              if ((int)uVar4 < 0) goto LAB_1400a4f9c;
            }
            if ((*(byte *)(*(longlong *)(uVar1 + 0x598) + 0x268) & 3) != 0) {
              if ((*(longlong *)(uVar1 + 0x828) != 0) && (*(longlong *)(uVar1 + 0x878) != 0)) {
                uVar4 = FUN_1400b1490(uVar1);
              }
              if ((int)uVar4 < 0) goto LAB_1400a4f9c;
            }
            if (*(int *)(uVar1 + 0x28) == 1) {
              pcVar8 = "rts_pnp_fdo_start_dev_delaywork";
              pcVar5 = "%s : Start after stop,so no need create pdos\n";
              DbgPrint(0x20,"%s : Start after stop,so no need create pdos\n",
                            "rts_pnp_fdo_start_dev_delaywork",(ulonglong)pcVar9);
LAB_1400a4eda:
              uVar6 = (ulonglong)pcVar5 & 0xffffffffffffff00 | 1;
              uVar4 = IoSetDeviceInterfaceState();
              if (-1 < (int)uVar4) {
                FUN_14001bab8(uVar1);
                FUN_14001c620(uVar1);
                FUN_1400aaf40(uVar1,uVar6,pcVar8,(ulonglong)pcVar9);
                uVar4 = FUN_1400a6b34(uVar1,uVar6,pcVar8,(ulonglong)pcVar9);
                if (uVar4 == 0) {
                  if (*(longlong *)(uVar1 + 0xbe8) == 0) goto LAB_1400a5065;
                  DbgPrint(0x20,"%s : ===><=== PoFxActivateComponent\n",
                                "rts_pnp_fdo_start_dev_delaywork",(ulonglong)pcVar9);
                  *(undefined *)(uVar1 + 0xbf3) = 1;
                  (*(code *)PTR__guard_dispatch_icall_1400e2370)(*(undefined8 *)(uVar1 + 0xbe8),0,1)
                  ;
                  *(undefined *)(uVar1 + 0xbf0) = 1;
                  *(undefined *)(uVar1 + 0xbf2) = 1;
                  DbgPrint(0x20,"%s : ===><=== PoFxStartDevicePowerManagement\n",
                                "rts_pnp_fdo_start_dev_delaywork",(ulonglong)pcVar9);
                  (*(code *)PTR__guard_dispatch_icall_1400e2370)(*(undefined8 *)(uVar1 + 0xbe8));
                }
                goto LAB_1400a4f94;
              }
              pcVar5 = "%s : IoSetDeviceInterfaceState:enable:failed\n";
            }
            else {
              uVar4 = FUN_140006cd4(param_1);
              if (-1 < (int)uVar4) goto LAB_1400a4eda;
              pcVar5 = "%s : rts_create_childen_pdos fail\n";
            }
            DbgPrint(0x20,pcVar5,"rts_pnp_fdo_start_dev_delaywork",(ulonglong)pcVar9);
            goto LAB_1400a4f94;
          }
        }
      }
    }
  }
  else {
LAB_1400a4f94:
    if (-1 < (int)uVar4) goto LAB_1400a5065;
  }
LAB_1400a4f9c:
  FUN_1400b19e0(uVar1);
  *(undefined *)(uVar1 + 0x3f1) = 0;
  FUN_1400b1da0(uVar1);
  *(undefined *)(uVar1 + 0x57a) = 0;
  FUN_1400b1bac(uVar1);
  *(undefined *)(uVar1 + 0xb28) = 0;
  FUN_1400b1c9c(uVar1);
  *(undefined *)(uVar1 + 0x3f0) = 0;
  FUN_1400b18f0(uVar1);
  *(undefined *)(uVar1 + 0x9b8) = 0;
  if (*(char *)(*(longlong *)(uVar1 + 1000) + 0x19f) != '\0') {
    FUN_1400b1aac(uVar1);
    *(undefined *)(uVar1 + 0xca0) = 0;
  }
  cVar7 = '\0';
  if ('\0' < *(char *)(uVar1 + 0x3f2)) {
    do {
      lVar10 = (longlong)cVar7;
      if (*(longlong *)(uVar1 + 0x618 + lVar10 * 8) != 0) {
        IoDeleteDevice();
      }
      cVar7 = cVar7 + '\x01';
      *(undefined8 *)(uVar1 + 0x618 + lVar10 * 8) = 0;
    } while (cVar7 < *(char *)(uVar1 + 0x3f2));
  }
  *(undefined *)(uVar1 + 0x3f2) = 0;
  IoSetDeviceInterfaceState(uVar1 + 0x98,0);
  KeSetEvent(uVar1 + 0x1a0,0,0);
LAB_1400a5065:
  *(uint *)(pcVar2 + 0x30) = uVar4;
  IofCompleteRequest(pcVar2,0);
  FUN_140005af8(uVar1);
  IoFreeWorkItem(*param_2);
  ExFreePoolWithTag(param_2,0);
  DbgPrint(0x2000,"%s : <- %s\n","rts_pnp_fdo_start_dev_delaywork",
                (ulonglong)"rts_pnp_fdo_start_dev_delaywork");
  return;
}
//-------------------------------------------[2]------------------------------------------------//
//File : thunk_FUN_1400b5c0c@1400b2700.c

uint thunk_FUN_1400b5c0c(ulonglong param_1,longlong param_2)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  char *pcVar8;
  char *pcVar9;
  code *pcVar10;
  char cVar11;
  code *pcVar12;
  code *pcVar13;
  undefined auStackX24 [8];
  undefined4 auStackX32 [2];
  
  DbgPrint(0x2000,"%s : -> %s\n","rts_pcie_specific_startup",
                (ulonglong)"rts_pcie_specific_startup");
  uVar3 = FUN_1400b37a4(param_1,param_2);
  if ((int)uVar3 < 0) {
    DbgPrint(1,"%s : rts_pcie_map_hw_resources failed: 0x%x \n","rts_pcie_specific_startup",
                  (ulonglong)uVar3);
  }
  else {
    cVar11 = '\0';
    pbVar1 = (byte *)(param_1 + 0x3fa);
    do {
      uVar3 = IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x18),0xe,4,pbVar1,auStackX24);
      if (uVar3 == 0) {
        uVar3 = IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x18),0x10,4,auStackX32,auStackX24);
        *(char *)(param_1 + 0x3fc) = (char)auStackX32[0];
        *(char *)(param_1 + 0x3fb) = (char)((uint)auStackX32[0] >> 0x10);
        if (uVar3 != 0) goto LAB_1400b5e0f;
        uVar5 = (ulonglong)*pbVar1;
        DbgPrint(0x80,"%s : rts_get_pci_bus_info ok,busNum %i, devNum %i, funcNum %i\n",
                      "rts_pcie_specific_startup",uVar5);
        uVar5 = FUN_1400a2550(param_1,'\x06','\x04',uVar5 & 0xffffffffffffff00 | (ulonglong)*pbVar1,
                              (char *)(param_1 + 0x3fd),(char *)(param_1 + 0x3fe),
                              (char *)(param_1 + 0x3ff),(undefined2 *)(param_1 + 0x406),
                              (undefined2 *)(param_1 + 0x408));
        uVar3 = (uint)uVar5;
        if (uVar3 != 0) {
          uVar5 = uVar5 & 0xffffffff;
          pcVar8 = "%s : rts_get_pci_bridge_info fail with 0x%x \n";
          goto LAB_1400b5e16;
        }
        uVar5 = (ulonglong)*(byte *)(param_1 + 0x3fd);
        pcVar8 = 
        "%s : rts_get_pci_bridge_info ok, pciBridgeBusNum %i, pciBridgeDevNum %i, pciBridgeFuncNum %i,pciBridgeVendorId 0x%x,pciBridgeDeviceId 0x%x \n"
        ;
        pcVar9 = "rts_pcie_specific_startup";
        DbgPrint(0x80,
                      "%s : rts_get_pci_bridge_info ok, pciBridgeBusNum %i, pciBridgeDevNum %i, pciBridgeFuncNum %i,pciBridgeVendorId 0x%x,pciBridgeDeviceId 0x%x \n"
                      ,"rts_pcie_specific_startup",uVar5);
        FUN_1400a2298(param_1);
        uVar6 = FUN_1400a2020(param_1,pcVar8,pcVar9,uVar5);
        uVar3 = (uint)uVar6;
      }
      else {
LAB_1400b5e0f:
        uVar5 = (ulonglong)uVar3;
        pcVar8 = "%s : rts_get_pci_bus_info fail with 0x%x \n";
LAB_1400b5e16:
        DbgPrint(0x80,pcVar8,"rts_pcie_specific_startup",uVar5);
      }
      cVar11 = cVar11 + '\x01';
    } while ((uVar3 != 0) && (cVar11 < '\x02'));
    uVar5 = (ulonglong)uVar3;
    DbgPrint(0x80,"%s : Get dev/host bus/dev/func No. return %#x \n",
                  "rts_pcie_specific_startup",uVar5);
    iVar4 = FUN_1400a30f4(param_1);
    pcVar8 = "rts_pcie_specific_startup";
    if (iVar4 == 0) {
      pcVar9 = "%s : cq_seq_enable: %d ,cq_rand_enable: %d\n";
      *(undefined4 *)(*(longlong *)(param_1 + 0x598) + 0x388) = 1;
      *(undefined *)(param_1 + 0xcf0) = 1;
      pcVar13 = (code *)(ulonglong)*(byte *)(*(longlong *)(param_1 + 1000) + 0x1a0);
      DbgPrint(0x20,"%s : cq_seq_enable: %d ,cq_rand_enable: %d\n","rts_pcie_specific_startup",
                    (ulonglong)pcVar13);
      lVar7 = *(longlong *)(param_1 + 1000);
      if ((*(char *)(lVar7 + 0x1a0) != '\0') || (*(char *)(lVar7 + 0x1a1) != '\0')) {
        *(undefined *)(lVar7 + 0x19f) = 1;
        *(undefined8 *)(param_1 + 0xc68) = 0;
        lVar7 = param_1 + 0xc90;
        *(longlong *)(param_1 + 0xc98) = lVar7;
        *(longlong *)lVar7 = lVar7;
        KeInitializeEvent(param_1 + 0xc78,1);
        lVar7 = param_1 + 0xc58;
        *(longlong *)(param_1 + 0xc60) = lVar7;
        *(longlong *)lVar7 = lVar7;
        pcVar13 = FUN_14009fce0;
        *(undefined8 *)(param_1 + 0xc50) = 0;
        pcVar12 = FUN_14009fda0;
        pcVar10 = FUN_14009f820;
        IoCsqInitialize(param_1 + 0xc10);
        *(undefined4 *)(param_1 + 0xcc8) = 0xffffffff;
        *(undefined4 *)(param_1 + 0xccc) = 0xffffffff;
        pcVar9 = (char *)pcVar10;
        pcVar8 = (char *)pcVar12;
      }
      FUN_14001aecc(param_1);
      FUN_1400b2518(param_1);
      FUN_14001cb1c(param_1,pcVar9,pcVar8,(ulonglong)pcVar13);
      lVar7 = *(longlong *)(param_1 + 0x598);
      if ((*(byte *)(lVar7 + 0x268) & 3) != 0) {
        uVar5 = param_1;
        FUN_1400b22e8(param_1,pcVar9,pcVar8,(ulonglong)pcVar13);
        uVar5 = uVar5 & 0xffffffffffffff00 |
                (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x10) + 0x4c);
        uVar6 = IoAllocateIrp(uVar5);
        *(undefined8 *)(param_1 + 0xb50) = uVar6;
        pcVar9 = (char *)0x0;
        uVar6 = IoAllocateIrp(uVar5 & 0xffffffffffffff00 |
                              (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x10) + 0x4c));
        *(undefined8 *)(param_1 + 0xb58) = uVar6;
        lVar7 = *(longlong *)(param_1 + 0x598);
      }
      if (((*(uint *)(lVar7 + 0x250) & 0x40000000) != 0) || (*(short *)(lVar7 + 0x2d2) == 0x5260)) {
        uVar6 = FUN_1400b2238(param_1,pcVar9,pcVar8,(ulonglong)pcVar13);
        uVar3 = (uint)uVar6;
        if (uVar3 != 0) {
          FUN_1400b2734(param_1);
          puVar2 = (uint *)(*(longlong *)(param_1 + 0x598) + 0x250);
          *puVar2 = *puVar2 & 0xbfffffff;
          DbgPrint(1,"%s : rts_alloc_4k_align_buffer failed, clear SD40_WRITE_SPEED_UP_EN \n",
                        "rts_pcie_specific_startup",(ulonglong)pcVar13);
          goto LAB_1400b5c73;
        }
      }
      DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pcie_specific_startup",
                    (ulonglong)"rts_pcie_specific_startup");
      return 0;
    }
    *(undefined *)(*(longlong *)(param_1 + 1000) + 3) = 2;
    DbgPrint(1,"%s : Everest init failed \n","rts_pcie_specific_startup",uVar5);
    uVar3 = 0xc0000001;
  }
LAB_1400b5c73:
  DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pcie_specific_startup",
                (ulonglong)"rts_pcie_specific_startup");
  return uVar3;
}
//-------------------------------------------[1]------------------------------------------------//
// File : FUN_1400b5c0c@1400b5c0c.c


uint FUN_1400b5c0c(ulonglong param_1,longlong param_2)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  char *pcVar8;
  char *pcVar9;
  code *pcVar10;
  char cVar11;
  code *pcVar12;
  code *pcVar13;
  undefined local_res18 [8];
  undefined4 local_res20 [2];
  
  DbgPrint(0x2000,"%s : -> %s\n","rts_pcie_specific_startup",
                (ulonglong)"rts_pcie_specific_startup");
  uVar3 = FUN_1400b37a4(param_1,param_2);
  if ((int)uVar3 < 0) {
    DbgPrint(1,"%s : rts_pcie_map_hw_resources failed: 0x%x \n","rts_pcie_specific_startup",
                  (ulonglong)uVar3);
  }
  else {
    cVar11 = '\0';
    pbVar1 = (byte *)(param_1 + 0x3fa);
    do {
      uVar3 = IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x18),0xe,4,pbVar1,local_res18);
      if (uVar3 == 0) {
        uVar3 = IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x18),0x10,4,local_res20,local_res18);
        *(char *)(param_1 + 0x3fc) = (char)local_res20[0];
        *(char *)(param_1 + 0x3fb) = (char)((uint)local_res20[0] >> 0x10);
        if (uVar3 != 0) goto LAB_1400b5e0f;
        uVar5 = (ulonglong)*pbVar1;
        DbgPrint(0x80,"%s : rts_get_pci_bus_info ok,busNum %i, devNum %i, funcNum %i\n",
                      "rts_pcie_specific_startup",uVar5);
        uVar5 = FUN_1400a2550(param_1,'\x06','\x04',uVar5 & 0xffffffffffffff00 | (ulonglong)*pbVar1,
                              (char *)(param_1 + 0x3fd),(char *)(param_1 + 0x3fe),
                              (char *)(param_1 + 0x3ff),(undefined2 *)(param_1 + 0x406),
                              (undefined2 *)(param_1 + 0x408));
        uVar3 = (uint)uVar5;
        if (uVar3 != 0) {
          uVar5 = uVar5 & 0xffffffff;
          pcVar8 = "%s : rts_get_pci_bridge_info fail with 0x%x \n";
          goto LAB_1400b5e16;
        }
        uVar5 = (ulonglong)*(byte *)(param_1 + 0x3fd);
        pcVar8 = 
        "%s : rts_get_pci_bridge_info ok, pciBridgeBusNum %i, pciBridgeDevNum %i, pciBridgeFuncNum %i,pciBridgeVendorId 0x%x,pciBridgeDeviceId 0x%x \n"
        ;
        pcVar9 = "rts_pcie_specific_startup";
        DbgPrint(0x80,
                      "%s : rts_get_pci_bridge_info ok, pciBridgeBusNum %i, pciBridgeDevNum %i, pciBridgeFuncNum %i,pciBridgeVendorId 0x%x,pciBridgeDeviceId 0x%x \n"
                      ,"rts_pcie_specific_startup",uVar5);
        FUN_1400a2298(param_1);
        uVar6 = FUN_1400a2020(param_1,pcVar8,pcVar9,uVar5);
        uVar3 = (uint)uVar6;
      }
      else {
LAB_1400b5e0f:
        uVar5 = (ulonglong)uVar3;
        pcVar8 = "%s : rts_get_pci_bus_info fail with 0x%x \n";
LAB_1400b5e16:
        DbgPrint(0x80,pcVar8,"rts_pcie_specific_startup",uVar5);
      }
      cVar11 = cVar11 + '\x01';
    } while ((uVar3 != 0) && (cVar11 < '\x02'));
    uVar5 = (ulonglong)uVar3;
    DbgPrint(0x80,"%s : Get dev/host bus/dev/func No. return %#x \n",
                  "rts_pcie_specific_startup",uVar5);
    iVar4 = FUN_1400a30f4(param_1);
    pcVar8 = "rts_pcie_specific_startup";
    if (iVar4 == 0) {
      pcVar9 = "%s : cq_seq_enable: %d ,cq_rand_enable: %d\n";
      *(undefined4 *)(*(longlong *)(param_1 + 0x598) + 0x388) = 1;
      *(undefined *)(param_1 + 0xcf0) = 1;
      pcVar13 = (code *)(ulonglong)*(byte *)(*(longlong *)(param_1 + 1000) + 0x1a0);
      DbgPrint(0x20,"%s : cq_seq_enable: %d ,cq_rand_enable: %d\n","rts_pcie_specific_startup",
                    (ulonglong)pcVar13);
      lVar7 = *(longlong *)(param_1 + 1000);
      if ((*(char *)(lVar7 + 0x1a0) != '\0') || (*(char *)(lVar7 + 0x1a1) != '\0')) {
        *(undefined *)(lVar7 + 0x19f) = 1;
        *(undefined8 *)(param_1 + 0xc68) = 0;
        lVar7 = param_1 + 0xc90;
        *(longlong *)(param_1 + 0xc98) = lVar7;
        *(longlong *)lVar7 = lVar7;
        KeInitializeEvent(param_1 + 0xc78,1);
        lVar7 = param_1 + 0xc58;
        *(longlong *)(param_1 + 0xc60) = lVar7;
        *(longlong *)lVar7 = lVar7;
        pcVar13 = FUN_14009fce0;
        *(undefined8 *)(param_1 + 0xc50) = 0;
        pcVar12 = FUN_14009fda0;
        pcVar10 = FUN_14009f820;
        IoCsqInitialize(param_1 + 0xc10);
        *(undefined4 *)(param_1 + 0xcc8) = 0xffffffff;
        *(undefined4 *)(param_1 + 0xccc) = 0xffffffff;
        pcVar9 = (char *)pcVar10;
        pcVar8 = (char *)pcVar12;
      }
      FUN_14001aecc(param_1);
      FUN_1400b2518(param_1);
      FUN_14001cb1c(param_1,pcVar9,pcVar8,(ulonglong)pcVar13);
      lVar7 = *(longlong *)(param_1 + 0x598);
      if ((*(byte *)(lVar7 + 0x268) & 3) != 0) {
        uVar5 = param_1;
        FUN_1400b22e8(param_1,pcVar9,pcVar8,(ulonglong)pcVar13);
        uVar5 = uVar5 & 0xffffffffffffff00 |
                (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x10) + 0x4c);
        uVar6 = IoAllocateIrp(uVar5);
        *(undefined8 *)(param_1 + 0xb50) = uVar6;
        pcVar9 = (char *)0x0;
        uVar6 = IoAllocateIrp(uVar5 & 0xffffffffffffff00 |
                              (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x10) + 0x4c));
        *(undefined8 *)(param_1 + 0xb58) = uVar6;
        lVar7 = *(longlong *)(param_1 + 0x598);
      }
      if (((*(uint *)(lVar7 + 0x250) & 0x40000000) != 0) || (*(short *)(lVar7 + 0x2d2) == 0x5260)) {
        uVar6 = FUN_1400b2238(param_1,pcVar9,pcVar8,(ulonglong)pcVar13);
        uVar3 = (uint)uVar6;
        if (uVar3 != 0) {
          FUN_1400b2734(param_1);
          puVar2 = (uint *)(*(longlong *)(param_1 + 0x598) + 0x250);
          *puVar2 = *puVar2 & 0xbfffffff;
          DbgPrint(1,"%s : rts_alloc_4k_align_buffer failed, clear SD40_WRITE_SPEED_UP_EN \n",
                        "rts_pcie_specific_startup",(ulonglong)pcVar13);
          goto LAB_1400b5c73;
        }
      }
      DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pcie_specific_startup",
                    (ulonglong)"rts_pcie_specific_startup");
      return 0;
    }
    *(undefined *)(*(longlong *)(param_1 + 1000) + 3) = 2;
    DbgPrint(1,"%s : Everest init failed \n","rts_pcie_specific_startup",uVar5);
    uVar3 = 0xc0000001;
  }
LAB_1400b5c73:
  DbgPrint(0x2000,"%s : <- %s, ret = 0x%x\n","rts_pcie_specific_startup",
                (ulonglong)"rts_pcie_specific_startup");
  return uVar3;
}
//-------------------------------------------------------------------------------------------//
//This Function is Called 2 Times by 2 Diffrent Functions FUN_1400b5c0c@1400b5c0c.c & thunk_FUN_1400b5c0c@1400b2700.c
//File : FUN_14001aecc@14001aecc.c

void FUN_14001aecc(longlong param_1)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  byte bVar4;
  ulonglong uVar5;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [2];
  
  DbgPrint(0x2000,"%s : -> %s\n","rts_load_rtd3_parameters_from_bios",
                (ulonglong)"rts_load_rtd3_parameters_from_bios");
  if (*(int *)(param_1 + 0x1d8) < 6) {
    uVar3 = FUN_1400737d0(param_1,0x724,local_res10);
    uVar5 = 0x724;
    if ((int)uVar3 == 0) {
      DbgPrint(0x100,"%s : GetBusData read %#x success %#x \n",
                    "rts_load_rtd3_parameters_from_bios",0x724);
      uVar3 = FUN_1400737d0(param_1,0x814,local_res18);
      uVar5 = 0x814;
      if ((int)uVar3 == 0) {
        DbgPrint(1,"%s : GetBusData read %#x success %#x \n",
                      "rts_load_rtd3_parameters_from_bios",0x814);
        if (*(char *)(*(longlong *)(param_1 + 1000) + 0x1f) == '\x01') {
          if (*(short *)(param_1 + 0x1de) == 0x5261) {
            uVar3 = FUN_1400737d0(param_1,0x81c,local_res8);
            uVar5 = 0x81c;
            if ((int)uVar3 != 0) goto LAB_14001b0e8;
            DbgPrint(1,"%s : GetBusData read %#x success %#x \n",
                          "rts_load_rtd3_parameters_from_bios",0x81c);
            uVar2 = local_res8[0] >> 0x10 & 3;
            if (uVar2 == 1 || uVar2 == 2) {
              DbgPrint(0x100,"%s : %s: BIOS valid \n","rts_load_rtd3_parameters_from_bios",
                            (ulonglong)"rts_load_rtd3_parameters_from_bios");
              bVar4 = (byte)(local_res8[0] >> 3);
LAB_14001b062:
              *(byte *)(*(longlong *)(param_1 + 1000) + 0xe6) = bVar4 & 1;
            }
          }
          else if ((local_res10[0] & 0x1000000) == 0) {
            DbgPrint(0x100,"%s : %s: BIOS valid \n","rts_load_rtd3_parameters_from_bios",
                          (ulonglong)"rts_load_rtd3_parameters_from_bios");
            sVar1 = *(short *)(param_1 + 0x1de);
            if ((sVar1 == 0x5227) || (sVar1 == 0x522a)) {
              *(byte *)(*(longlong *)(param_1 + 1000) + 0xe6) = (byte)(local_res18[0] >> 1) & 1;
            }
            else if ((((ushort)(sVar1 + 0xadb7U) < 0x12) &&
                     ((0x20083U >> ((ushort)(sVar1 + 0xadb7U) & 0x1f) & 1) != 0)) ||
                    (local_res18[0] = local_res10[0], sVar1 == 0x5287)) {
              bVar4 = (byte)(local_res18[0] >> 2);
              goto LAB_14001b062;
            }
          }
        }
        DbgPrint(0x100,"%s : %s: rtd3_en = %#x \n","rts_load_rtd3_parameters_from_bios",
                      (ulonglong)"rts_load_rtd3_parameters_from_bios");
        goto LAB_14001b0bf;
      }
    }
LAB_14001b0e8:
    DbgPrint(1,"%s : GetBusData read %#x fail \n","rts_load_rtd3_parameters_from_bios",uVar5);
  }
  else {
LAB_14001b0bf:
    DbgPrint(0x2000,"%s : <- %s\n","rts_load_rtd3_parameters_from_bios",
                  (ulonglong)"rts_load_rtd3_parameters_from_bios");
  }
  return;
}
//-------------------------------------------------------------------------------------------//
//This Function is Called by One Function (FUN_14001aecc@14001aecc.c) 3 Times FUN_14001aecc@14001aecc.c
//File : FUN_1400737d0@1400737d0.c

undefined8 FUN_1400737d0(longlong param_1,ushort param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  uVar2 = (uint)param_2;
  DbgPrint(0x10,"%s : -><- cr_common_rd_cfg32, addr %#x \n","rts_cr_rd_cfg32",(ulonglong)uVar2)
  ;
  if ((*(char *)(param_1 + 0x700) == '\0') ||
     (*(char *)(*(longlong *)(param_1 + 1000) + 0x138) == '\0')) {
    (*(code *)PTR__guard_dispatch_icall_1400e2370)
              (*(undefined8 *)(param_1 + 0x4b8),0,local_res10,uVar2,4);
  }
  else {
    lVar1 = FUN_1400a1b4c((((ulonglong)*(byte *)(param_1 + 0x3fa) << 5 |
                           (ulonglong)*(byte *)(param_1 + 0x3fb)) << 3 |
                          (ulonglong)*(byte *)(param_1 + 0x3fc)) * 0x1000 +
                          *(longlong *)(param_1 + 0x6f0),0x1000);
    if (lVar1 == 0) {
      DbgPrint(0x10,"%s : -><- SetHostASPM, MapPhyMem failed \n","rts_cr_rd_cfg32",0);
      return 1;
    }
    local_res10[0] = *(undefined4 *)((ulonglong)param_2 + lVar1);
    FUN_1400a1c60(lVar1,0x1000);
  }
  *param_3 = local_res10[0];
  DbgPrint(0x10,"%s : -><- cr_common_rd_cfg32, addr %#x val %#x \n","rts_cr_rd_cfg32",
                (ulonglong)uVar2);
  return 0;
}
//-------------------------------------------------------------------------------------------//
//Just a Function Wrapper to MmMapIoSpace(); 
//File : FUN_1400a1b4c@1400a1b4c.c

void FUN_1400a1b4c(undefined8 param_1,undefined4 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001400a1b51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MmMapIoSpace(param_1,param_2,0);
  return;
}