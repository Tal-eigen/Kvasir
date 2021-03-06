#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//External Bus Interface
    namespace ExbusMode0{    ///<Mode Register 0
        using Addr = Register::Address<0x4003f000,0xffffc400,0x00000000,unsigned>;
        ///select how to set the MOEX width
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,unsigned> moexeup{}; 
        ///select a CS assertion from the start of accessing to the end of address output
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,unsigned> mpxcsof{}; 
        ///select whether or not the address is output to the data lines in multiplex mode
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,unsigned> mpxdoff{}; 
        ///set up the polarity of the ALE signal
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,unsigned> aleinv{}; 
        ///select operation bus mode
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,unsigned> mpxmode{}; 
        ///select to which idle cycle the write data output is extended
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> shrtdout{}; 
        ///control the external RDY function
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> rdy{}; 
        ///NOR Flash memory page access mode 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> page{}; 
        ///NAND Flash memory mode
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> nand{}; 
        ///disable the write enable signal (MWEX) operation
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> weoff{}; 
        ///Read Byte Mask ON
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> rbmon{}; 
        ///specify Data Width 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,unsigned> wdth{}; 
    }
    namespace ExbusMode1{    ///<Mode Register 1
        using Addr = Register::Address<0x4003f004,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode2{    ///<Mode Register 2
        using Addr = Register::Address<0x4003f008,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode3{    ///<Mode Register 3
        using Addr = Register::Address<0x4003f00c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode4{    ///<Mode Register 4
        using Addr = Register::Address<0x4003f010,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode5{    ///<Mode Register 5
        using Addr = Register::Address<0x4003f014,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode6{    ///<Mode Register 6
        using Addr = Register::Address<0x4003f018,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode7{    ///<Mode Register 7
        using Addr = Register::Address<0x4003f01c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim0{    ///<Timing Register 0
        using Addr = Register::Address<0x4003f020,0x00000000,0x00000000,unsigned>;
        ///Write Idle Cycle 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,28),Register::ReadWriteAccess,unsigned> widlc{}; 
        ///Write Enable Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(27,24),Register::ReadWriteAccess,unsigned> wwec{}; 
        ///Write Address Setup cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> wadc{}; 
        ///Write Access Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,16),Register::ReadWriteAccess,unsigned> wacc{}; 
        ///Read Idle Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,12),Register::ReadWriteAccess,unsigned> ridlc{}; 
        ///First Read Address Cycle 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> fradc{}; 
        ///Read Address Setup cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,4),Register::ReadWriteAccess,unsigned> radc{}; 
        ///Read Access Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> racc{}; 
    }
    namespace ExbusTim1{    ///<Timing Register 1
        using Addr = Register::Address<0x4003f024,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim2{    ///<Timing Register 2
        using Addr = Register::Address<0x4003f028,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim3{    ///<Timing Register 3
        using Addr = Register::Address<0x4003f02c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim4{    ///<Timing Register 4
        using Addr = Register::Address<0x4003f030,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim5{    ///<Timing Register 5
        using Addr = Register::Address<0x4003f034,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim6{    ///<Timing Register 6
        using Addr = Register::Address<0x4003f038,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim7{    ///<Timing Register 7
        using Addr = Register::Address<0x4003f03c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusArea0{    ///<Area Register 0
        using Addr = Register::Address<0x4003f040,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea1{    ///<Area Register 1
        using Addr = Register::Address<0x4003f044,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea2{    ///<Area Register 2
        using Addr = Register::Address<0x4003f048,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea3{    ///<Area Register 3
        using Addr = Register::Address<0x4003f04c,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea4{    ///<Area Register 4
        using Addr = Register::Address<0x4003f050,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea5{    ///<Area Register 5
        using Addr = Register::Address<0x4003f054,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea6{    ///<Area Register 6
        using Addr = Register::Address<0x4003f058,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea7{    ///<Area Register 7
        using Addr = Register::Address<0x4003f05c,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusAtim0{    ///<ALE Timing Register 0
        using Addr = Register::Address<0x4003f060,0xfffff000,0x00000000,unsigned>;
        ///Address Latch Enable Width 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> alew{}; 
        ///Address Latch Enable Setup cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,4),Register::ReadWriteAccess,unsigned> ales{}; 
        ///Address Latch Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> alc{}; 
    }
    namespace ExbusAtim1{    ///<ALE Timing Register 1
        using Addr = Register::Address<0x4003f064,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusAtim2{    ///<ALE Timing Register 2
        using Addr = Register::Address<0x4003f068,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusAtim3{    ///<ALE Timing Register 3
        using Addr = Register::Address<0x4003f06c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusAtim4{    ///<ALE Timing Register 4
        using Addr = Register::Address<0x4003f070,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusAtim5{    ///<ALE Timing Register 5
        using Addr = Register::Address<0x4003f074,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusAtim6{    ///<ALE Timing Register 6
        using Addr = Register::Address<0x4003f078,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusAtim7{    ///<ALE Timing Register 7
        using Addr = Register::Address<0x4003f07c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusSdmode{    ///<SDRAM Mode Register
        using Addr = Register::Address<0x4003f100,0xfffe00c8,0x00000000,unsigned>;
        ///MSDCLK OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> msdclkoff{}; 
        ///Bank Address Select
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,12),Register::ReadWriteAccess,unsigned> basel{}; 
        ///Row Address Select
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> rasel{}; 
        ///Column Address Select
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,4),Register::ReadWriteAccess,unsigned> casel{}; 
        ///Refresh OFF
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> roff{}; 
        ///Power Down ON
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> pdon{}; 
        ///SDRAM ON
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> sdon{}; 
    }
    namespace ExbusReftim{    ///<Refresh Timer Register
        using Addr = Register::Address<0x4003f104,0xfe000000,0x00000000,unsigned>;
        ///Pre-Refresh
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(24,24),Register::ReadWriteAccess,unsigned> pref{}; 
        ///Number of Refresh
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::ReadWriteAccess,unsigned> nref{}; 
        ///Refresh Count
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> refc{}; 
    }
    namespace ExbusPwrdwn{    ///<Power Down Count Register
        using Addr = Register::Address<0x4003f108,0xffff0000,0x00000000,unsigned>;
        ///Power Down Count
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> pdc{}; 
    }
    namespace ExbusSdtim{    ///<SDRAM Timing Register
        using Addr = Register::Address<0x4003f10c,0xfc00000c,0x00000000,unsigned>;
        ///Data-in to Precharge Lead Time
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(25,24),Register::ReadWriteAccess,unsigned> tdpl{}; 
        ///Refresh Cycle time
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> trefc{}; 
        ///RAS active time
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,16),Register::ReadWriteAccess,unsigned> tras{}; 
        ///RAS-CAS Delay
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,12),Register::ReadWriteAccess,unsigned> trcd{}; 
        ///RAS Precharge time
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> trp{}; 
        ///RAS Cycle time
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,4),Register::ReadWriteAccess,unsigned> trc{}; 
        ///CAS Latency
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,unsigned> cl{}; 
    }
    namespace ExbusSdcmd{    ///<SDRAM Command Register
        using Addr = Register::Address<0x4003f110,0x7fe00000,0x00000000,unsigned>;
        ///Pend
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> pend{}; 
        ///SDRAM CKE
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(20,20),Register::ReadWriteAccess,unsigned> sdcke{}; 
        ///SDRAM Chip Select
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,19),Register::ReadWriteAccess,unsigned> sdcs{}; 
        ///SDRAM RAS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(18,18),Register::ReadWriteAccess,unsigned> sdras{}; 
        ///SDRAM CAS
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,unsigned> sdcas{}; 
        ///SDRAM Write Enable
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,16),Register::ReadWriteAccess,unsigned> sdwe{}; 
        ///SDRAM ADress
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> sdad{}; 
    }
    namespace ExbusMemcerr{    ///<Memory Controller Register
        using Addr = Register::Address<0x4003f200,0xfffffff0,0x00000000,unsigned>;
        ///SDRAM error Interrupt ON
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> sdion{}; 
        ///SRAM/Flash error Interrupt ON
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> sfion{}; 
        ///SDRAM Error
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> sder{}; 
        ///SRAM/Flash Error
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> sfer{}; 
    }
    namespace ExbusDclkr{    ///<Division Clock Register
        using Addr = Register::Address<0x4003f300,0xffffffe0,0x00000000,unsigned>;
        ///MCLK ON
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> mclkon{}; 
        ///MCLK Division Ratio Setup
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> mdiv{}; 
    }
    namespace ExbusEst{    ///<Error Status Register
        using Addr = Register::Address<0x4003f304,0xfffffffe,0x00000000,unsigned>;
        ///WERR
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> werr{}; 
    }
    namespace ExbusWead{    ///<Write Error Address Register
        using Addr = Register::Address<0x4003f308,0x00000000,0x00000000,unsigned>;
        ///ADDR
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> addr{}; 
    }
    namespace ExbusEsclr{    ///<Error Status Clear Register
        using Addr = Register::Address<0x4003f30c,0xfffffffe,0x00000000,unsigned>;
        ///Write Error Clear
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::writeOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> werrclr{}; 
    }
    namespace ExbusAmode{    ///<Access Mode Register
        using Addr = Register::Address<0x4003f310,0xfffffffe,0x00000000,unsigned>;
        ///WAEN
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> waen{}; 
    }
}
