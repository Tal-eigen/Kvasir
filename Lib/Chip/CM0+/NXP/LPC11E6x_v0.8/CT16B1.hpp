#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//16-bit counter/timers CT16B1
    namespace Ct16b1Ir{    ///<Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending.
        using Addr = Register::Address<0x40010000,0x00000000,0x00000000,unsigned>;
        ///Interrupt flag for match channel 0.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> mr0int{}; 
        ///Interrupt flag for match channel 1.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> mr1int{}; 
        ///Interrupt flag for match channel 2.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> mr2int{}; 
        ///Interrupt flag for match channel 3.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> mr3int{}; 
        ///Interrupt flag for capture channel 0 event.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> cr0int{}; 
        ///Interrupt flag for capture channel 1 event.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> cr1int{}; 
        ///Interrupt flag for capture channel 2 event.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> cr2int{}; 
        ///Reserved
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,7),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Tcr{    ///<Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR.
        using Addr = Register::Address<0x40010004,0x00000000,0x00000000,unsigned>;
        ///Counter enable.
        enum class CenVal {
            disabled=0x00000000,     ///<The counters are disabled.
            enabled=0x00000001,     ///<The Timer Counter and Prescale Counter are enabled for counting.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,CenVal> cen{}; 
        namespace CenValC{
            constexpr Register::FieldValue<decltype(cen)::Type,CenVal::disabled> disabled{};
            constexpr Register::FieldValue<decltype(cen)::Type,CenVal::enabled> enabled{};
        }
        ///Counter reset.
        enum class CrstVal {
            nop=0x00000000,     ///<Do nothing.
            reset=0x00000001,     ///<The Timer Counter and the Prescale Counter are synchronously reset on the next positive edge of PCLK. The counters remain reset until TCR[1] is returned to zero.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,CrstVal> crst{}; 
        namespace CrstValC{
            constexpr Register::FieldValue<decltype(crst)::Type,CrstVal::nop> nop{};
            constexpr Register::FieldValue<decltype(crst)::Type,CrstVal::reset> reset{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,2),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Tc{    ///<Timer Counter. The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR.
        using Addr = Register::Address<0x40010008,0x00000000,0x00000000,unsigned>;
        ///Timer counter value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> tcval{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Pr{    ///<Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC.
        using Addr = Register::Address<0x4001000c,0x00000000,0x00000000,unsigned>;
        ///Prescale value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> pcval{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Pc{    ///<Prescale Counter. The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface.
        using Addr = Register::Address<0x40010010,0x00000000,0x00000000,unsigned>;
        ///Prescale counter value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> pc{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mcr{    ///<Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs.
        using Addr = Register::Address<0x40010014,0x00000000,0x00000000,unsigned>;
        ///Interrupt on MR0: an interrupt is generated when MR0 matches the value in the TC.
        enum class Mr0iVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,Mr0iVal> mr0i{}; 
        namespace Mr0iValC{
            constexpr Register::FieldValue<decltype(mr0i)::Type,Mr0iVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr0i)::Type,Mr0iVal::disabled> disabled{};
        }
        ///Reset on MR0: the TC will be reset if MR0 matches it.
        enum class Mr0rVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,Mr0rVal> mr0r{}; 
        namespace Mr0rValC{
            constexpr Register::FieldValue<decltype(mr0r)::Type,Mr0rVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr0r)::Type,Mr0rVal::disabled> disabled{};
        }
        ///Stop on MR0: the TC and PC will be stopped and TCR[0] will be set to 0 if MR0 matches the TC.
        enum class Mr0sVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,Mr0sVal> mr0s{}; 
        namespace Mr0sValC{
            constexpr Register::FieldValue<decltype(mr0s)::Type,Mr0sVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr0s)::Type,Mr0sVal::disabled> disabled{};
        }
        ///Interrupt on MR1: an interrupt is generated when MR1 matches the value in the TC.
        enum class Mr1iVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,Mr1iVal> mr1i{}; 
        namespace Mr1iValC{
            constexpr Register::FieldValue<decltype(mr1i)::Type,Mr1iVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr1i)::Type,Mr1iVal::disabled> disabled{};
        }
        ///Reset on MR1: the TC will be reset if MR1 matches it.
        enum class Mr1rVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,Mr1rVal> mr1r{}; 
        namespace Mr1rValC{
            constexpr Register::FieldValue<decltype(mr1r)::Type,Mr1rVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr1r)::Type,Mr1rVal::disabled> disabled{};
        }
        ///Stop on MR1: the TC and PC will be stopped and TCR[0] will be set to 0 if MR1 matches the TC.
        enum class Mr1sVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,Mr1sVal> mr1s{}; 
        namespace Mr1sValC{
            constexpr Register::FieldValue<decltype(mr1s)::Type,Mr1sVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr1s)::Type,Mr1sVal::disabled> disabled{};
        }
        ///Interrupt on MR2: an interrupt is generated when MR2 matches the value in the TC.
        enum class Mr2iVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,Mr2iVal> mr2i{}; 
        namespace Mr2iValC{
            constexpr Register::FieldValue<decltype(mr2i)::Type,Mr2iVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr2i)::Type,Mr2iVal::disabled> disabled{};
        }
        ///Reset on MR2: the TC will be reset if MR2 matches it.
        enum class Mr2rVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,Mr2rVal> mr2r{}; 
        namespace Mr2rValC{
            constexpr Register::FieldValue<decltype(mr2r)::Type,Mr2rVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr2r)::Type,Mr2rVal::disabled> disabled{};
        }
        ///Stop on MR2: the TC and PC will be stopped and TCR[0] will be set to 0 if MR2 matches the TC.
        enum class Mr2sVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,Mr2sVal> mr2s{}; 
        namespace Mr2sValC{
            constexpr Register::FieldValue<decltype(mr2s)::Type,Mr2sVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr2s)::Type,Mr2sVal::disabled> disabled{};
        }
        ///Interrupt on MR3: an interrupt is generated when MR3 matches the value in the TC.
        enum class Mr3iVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,Mr3iVal> mr3i{}; 
        namespace Mr3iValC{
            constexpr Register::FieldValue<decltype(mr3i)::Type,Mr3iVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr3i)::Type,Mr3iVal::disabled> disabled{};
        }
        ///Reset on MR3: the TC will be reset if MR3 matches it.
        enum class Mr3rVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,Mr3rVal> mr3r{}; 
        namespace Mr3rValC{
            constexpr Register::FieldValue<decltype(mr3r)::Type,Mr3rVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr3r)::Type,Mr3rVal::disabled> disabled{};
        }
        ///Stop on MR3: the TC and PC will be stopped and TCR[0] will be set to 0 if MR3 matches the TC.
        enum class Mr3sVal {
            enabled=0x00000001,     ///<Enabled
            disabled=0x00000000,     ///<Disabled
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,Mr3sVal> mr3s{}; 
        namespace Mr3sValC{
            constexpr Register::FieldValue<decltype(mr3s)::Type,Mr3sVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(mr3s)::Type,Mr3sVal::disabled> disabled{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,12),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Ccr{    ///<Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place.
        using Addr = Register::Address<0x40010028,0x00000000,0x00000000,unsigned>;
        ///Rising edge of capture channel 0:  a sequence of 0 then 1 causes CR0 to be loaded with the contents of TC.
        enum class Cap0reVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,Cap0reVal> cap0re{}; 
        namespace Cap0reValC{
            constexpr Register::FieldValue<decltype(cap0re)::Type,Cap0reVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap0re)::Type,Cap0reVal::disabled> disabled{};
        }
        ///Falling edge of capture channel 0:: a sequence of 1 then 0 causes CR0 to be loaded with the contents of TC.
        enum class Cap0feVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,Cap0feVal> cap0fe{}; 
        namespace Cap0feValC{
            constexpr Register::FieldValue<decltype(cap0fe)::Type,Cap0feVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap0fe)::Type,Cap0feVal::disabled> disabled{};
        }
        ///Generate interrupt on channel 0 capture event: a CR0 load  generates an interrupt.
        enum class Cap0iVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,Cap0iVal> cap0i{}; 
        namespace Cap0iValC{
            constexpr Register::FieldValue<decltype(cap0i)::Type,Cap0iVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap0i)::Type,Cap0iVal::disabled> disabled{};
        }
        ///Rising edge of capture channel 1:  a sequence of 0 then 1 causes CR1 to be loaded with the contents of TC.
        enum class Cap1reVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,Cap1reVal> cap1re{}; 
        namespace Cap1reValC{
            constexpr Register::FieldValue<decltype(cap1re)::Type,Cap1reVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap1re)::Type,Cap1reVal::disabled> disabled{};
        }
        ///Falling edge of capture channel 1:: a sequence of 1 then 0 causes CR1 to be loaded with the contents of TC.
        enum class Cap1feVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,Cap1feVal> cap1fe{}; 
        namespace Cap1feValC{
            constexpr Register::FieldValue<decltype(cap1fe)::Type,Cap1feVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap1fe)::Type,Cap1feVal::disabled> disabled{};
        }
        ///Generate interrupt on channel 1 capture event: a CR1 load  generates an interrupt.
        enum class Cap1iVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,Cap1iVal> cap1i{}; 
        namespace Cap1iValC{
            constexpr Register::FieldValue<decltype(cap1i)::Type,Cap1iVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap1i)::Type,Cap1iVal::disabled> disabled{};
        }
        ///Rising edge of capture channel 2:  a sequence of 0 then 1 causes CR2 to be loaded with the contents of TC.
        enum class Cap2reVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,Cap2reVal> cap2re{}; 
        namespace Cap2reValC{
            constexpr Register::FieldValue<decltype(cap2re)::Type,Cap2reVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap2re)::Type,Cap2reVal::disabled> disabled{};
        }
        ///Falling edge of capture channel 2: a sequence of 1 then 0 causes CR2 to be loaded with the contents of TC.
        enum class Cap2feVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,Cap2feVal> cap2fe{}; 
        namespace Cap2feValC{
            constexpr Register::FieldValue<decltype(cap2fe)::Type,Cap2feVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap2fe)::Type,Cap2feVal::disabled> disabled{};
        }
        ///Generate interrupt on channel 2 capture event: a CR2 load  generates an interrupt.
        enum class Cap2iVal {
            enabled=0x00000001,     ///<Enabled.
            disabled=0x00000000,     ///<Disabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,Cap2iVal> cap2i{}; 
        namespace Cap2iValC{
            constexpr Register::FieldValue<decltype(cap2i)::Type,Cap2iVal::enabled> enabled{};
            constexpr Register::FieldValue<decltype(cap2i)::Type,Cap2iVal::disabled> disabled{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,9),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Emr{    ///<External Match Register. The EMR controls the match function and the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0].
        using Addr = Register::Address<0x4001003c,0x00000000,0x00000000,unsigned>;
        ///External Match 0. This bit reflects the state of output CT16B0_MAT0/CT16B1_MAT0, whether or not this output is connected to its pin. When a match occurs between the TC and MR0, this bit can either toggle, go LOW, go HIGH, or do nothing. Bits EMR[5:4] control the functionality of this output. This bit is driven to the CT16B0_MAT0/CT16B1_MAT0 pins if the match function is selected in the IOCON registers (0 = LOW, 1 = HIGH).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,unsigned> em0{}; 
        ///External Match 1. This bit reflects the state of output CT16B0_MAT1/CT16B1_MAT1, whether or not this output is connected to its pin. When a match occurs between the TC and MR1, this bit can either toggle, go LOW, go HIGH, or do nothing. Bits EMR[7:6] control the functionality of this output. This bit is driven to the CT16B0_MAT0/CT16B1_MAT0 pins if the match function is selected in the IOCON registers (0 = LOW, 1 = HIGH).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,unsigned> em1{}; 
        ///External Match 2. This bit reflects the state of match channel 2. When a match occurs between the TC and MR2, this bit can either toggle, go LOW, go HIGH, or do nothing. Bits EMR[9:8] control the functionality of this output.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> em2{}; 
        ///External Match 3. This bit reflects the state of output of match channel 3. When a match occurs between the TC and MR3, this bit can either toggle, go LOW, go HIGH, or do nothing. Bits EMR[11:10] control the functionality of this output.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> em3{}; 
        ///External Match Control 0. Determines the functionality of External Match 0. Table 267 shows the encoding of these bits.
        enum class Emc0Val {
            nop=0x00000000,     ///<Do Nothing.
            clear=0x00000001,     ///<Clear. Clear thecorresponding External Match bit/output to 0 (CT16Bn_MAT0 pin isLOW if pinned out).
            set=0x00000002,     ///<Set. Set the corresponding External Match bit/output to 1(CT16Bn_MAT0 pin is HIGH if pinned out).
            toggle=0x00000003,     ///<Toggle. Toggle the correspondingExternal Match bit/output.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,4),Register::ReadWriteAccess,Emc0Val> emc0{}; 
        namespace Emc0ValC{
            constexpr Register::FieldValue<decltype(emc0)::Type,Emc0Val::nop> nop{};
            constexpr Register::FieldValue<decltype(emc0)::Type,Emc0Val::clear> clear{};
            constexpr Register::FieldValue<decltype(emc0)::Type,Emc0Val::set> set{};
            constexpr Register::FieldValue<decltype(emc0)::Type,Emc0Val::toggle> toggle{};
        }
        ///External Match Control 1. Determines the functionality of External Match 1.
        enum class Emc1Val {
            nop=0x00000000,     ///<Do Nothing.
            clear=0x00000001,     ///<Clear. Clear thecorresponding External Match bit/output to 0 (CT16Bn_MAT0 pin isLOW if pinned out).
            set=0x00000002,     ///<Set. Set the corresponding External Match bit/output to 1(CT16Bn_MAT0 pin is HIGH if pinned out).
            toggle=0x00000003,     ///<Toggle. Toggle the correspondingExternal Match bit/output.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,6),Register::ReadWriteAccess,Emc1Val> emc1{}; 
        namespace Emc1ValC{
            constexpr Register::FieldValue<decltype(emc1)::Type,Emc1Val::nop> nop{};
            constexpr Register::FieldValue<decltype(emc1)::Type,Emc1Val::clear> clear{};
            constexpr Register::FieldValue<decltype(emc1)::Type,Emc1Val::set> set{};
            constexpr Register::FieldValue<decltype(emc1)::Type,Emc1Val::toggle> toggle{};
        }
        ///External Match Control 2. Determines the functionality of External Match 2.
        enum class Emc2Val {
            nop=0x00000000,     ///<Do Nothing.
            clear=0x00000001,     ///<Clear. Clear thecorresponding External Match bit/output to 0 (CT16Bn_MAT0 pin isLOW if pinned out).
            set=0x00000002,     ///<Set. Set the corresponding External Match bit/output to 1(CT16Bn_MAT0 pin is HIGH if pinned out).
            toggle=0x00000003,     ///<Toggle. Toggle the correspondingExternal Match bit/output.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,8),Register::ReadWriteAccess,Emc2Val> emc2{}; 
        namespace Emc2ValC{
            constexpr Register::FieldValue<decltype(emc2)::Type,Emc2Val::nop> nop{};
            constexpr Register::FieldValue<decltype(emc2)::Type,Emc2Val::clear> clear{};
            constexpr Register::FieldValue<decltype(emc2)::Type,Emc2Val::set> set{};
            constexpr Register::FieldValue<decltype(emc2)::Type,Emc2Val::toggle> toggle{};
        }
        ///External Match Control 3. Determines the functionality of External Match 3.
        enum class Emc3Val {
            nop=0x00000000,     ///<Do Nothing.
            clear=0x00000001,     ///<Clear. Clear thecorresponding External Match bit/output to 0 (CT16Bn_MAT0 pin isLOW if pinned out).
            set=0x00000002,     ///<Set. Set the corresponding External Match bit/output to 1(CT16Bn_MAT0 pin is HIGH if pinned out).
            toggle=0x00000003,     ///<Toggle. Toggle the correspondingExternal Match bit/output.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,10),Register::ReadWriteAccess,Emc3Val> emc3{}; 
        namespace Emc3ValC{
            constexpr Register::FieldValue<decltype(emc3)::Type,Emc3Val::nop> nop{};
            constexpr Register::FieldValue<decltype(emc3)::Type,Emc3Val::clear> clear{};
            constexpr Register::FieldValue<decltype(emc3)::Type,Emc3Val::set> set{};
            constexpr Register::FieldValue<decltype(emc3)::Type,Emc3Val::toggle> toggle{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,12),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Ctcr{    ///<Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting.
        using Addr = Register::Address<0x40010070,0x00000000,0x00000000,unsigned>;
        ///Counter/Timer Mode. This field selects which rising PCLK edges can increment Timer's Prescale Counter (PC), or clear PC and increment Timer Counter (TC). If Counter mode is selected in the CTCR, bits 2:0 in the Capture Control Register (CCR) must be programmed as 000.
        enum class CtmVal {
            timerMode=0x00000000,     ///<Timer Mode.  Increments every rising PCLK edge
            rising=0x00000001,     ///<Counter Moderising edge. . TC is incremented on rising edges on the CAP input selected by bits 3:2.
            falling=0x00000002,     ///<Counter Mode falling edge: TC is incremented on falling edges on the CAP input selected by bits 3:2.
            dual=0x00000003,     ///<Counter Mode dual edge: TC is incremented on both edges on the CAP input selected by bits 3:2.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,CtmVal> ctm{}; 
        namespace CtmValC{
            constexpr Register::FieldValue<decltype(ctm)::Type,CtmVal::timerMode> timerMode{};
            constexpr Register::FieldValue<decltype(ctm)::Type,CtmVal::rising> rising{};
            constexpr Register::FieldValue<decltype(ctm)::Type,CtmVal::falling> falling{};
            constexpr Register::FieldValue<decltype(ctm)::Type,CtmVal::dual> dual{};
        }
        ///Count Input Select. In counter mode (when bits 1:0 in this register are not 00), these bits select which CAP pin is sampled for clocking. Value 0x3 isreserved.
        enum class CisVal {
            captureChannel0=0x00000000,     ///<Capture channel 0.
            captureChannel1=0x00000001,     ///<Capture channel 1.
            captureChannel2=0x00000002,     ///<Capture channel 2.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,2),Register::ReadWriteAccess,CisVal> cis{}; 
        namespace CisValC{
            constexpr Register::FieldValue<decltype(cis)::Type,CisVal::captureChannel0> captureChannel0{};
            constexpr Register::FieldValue<decltype(cis)::Type,CisVal::captureChannel1> captureChannel1{};
            constexpr Register::FieldValue<decltype(cis)::Type,CisVal::captureChannel2> captureChannel2{};
        }
        ///Setting this bit to 1 enables clearing of the timer and the prescaler when the capture-edge event specified in bits 7:5 occurs.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> encc{}; 
        ///Edge select. When bit 4 is 1, these bits select which capture input edge will cause the timer and prescaler to be cleared. These bits have no effect when bit 4 is low. Values 0x2 to 0x3 and 0x6 to 0x7 are reserved.
        enum class SelccVal {
            cap0rising=0x00000000,     ///<Rising Edge of thesignal on capture channel 0 clears the timer (if bit 4 is set).
            cap0falling=0x00000001,     ///<Falling Edge of thesignal on capture channel 0 clears the timer (if bit 4 is set).
            cap1rising=0x00000002,     ///<Rising Edge of thesignal on capture channel 1 clears the timer (if bit 4 is set).
            cap1falling=0x00000003,     ///<Falling Edge of thesignal on capture channel 1 clears the timer (if bit 4 is set).
            cap2rising=0x00000004,     ///<Rising Edge of thesignal on capture channel 2 clears the timer (if bit 4 is set).
            cap1falling=0x00000005,     ///<Falling Edge of thesignal on capture channel 2 clears the timer (if bit 4 is set).
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,5),Register::ReadWriteAccess,SelccVal> selcc{}; 
        namespace SelccValC{
            constexpr Register::FieldValue<decltype(selcc)::Type,SelccVal::cap0rising> cap0rising{};
            constexpr Register::FieldValue<decltype(selcc)::Type,SelccVal::cap0falling> cap0falling{};
            constexpr Register::FieldValue<decltype(selcc)::Type,SelccVal::cap1rising> cap1rising{};
            constexpr Register::FieldValue<decltype(selcc)::Type,SelccVal::cap1falling> cap1falling{};
            constexpr Register::FieldValue<decltype(selcc)::Type,SelccVal::cap2rising> cap2rising{};
            constexpr Register::FieldValue<decltype(selcc)::Type,SelccVal::cap1falling> cap1falling{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,8),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Pwmc{    ///<PWM Control Register. The PWMCON enables PWM mode for the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0].
        using Addr = Register::Address<0x40010074,0x00000000,0x00000000,unsigned>;
        ///PWM mode enable for channel0.
        enum class Pwmen0Val {
            em0=0x00000000,     ///<CT16Bn_MAT0 is controlled by EM0.
            pwm=0x00000001,     ///<PWM mode is enabled for CT16Bn_MAT0.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,Pwmen0Val> pwmen0{}; 
        namespace Pwmen0ValC{
            constexpr Register::FieldValue<decltype(pwmen0)::Type,Pwmen0Val::em0> em0{};
            constexpr Register::FieldValue<decltype(pwmen0)::Type,Pwmen0Val::pwm> pwm{};
        }
        ///PWM mode enable for channel1.
        enum class Pwmen1Val {
            em1=0x00000000,     ///<CT16Bn_MAT01 is controlled by EM1.
            pwm=0x00000001,     ///<PWM mode is enabled for CT16Bn_MAT1.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,Pwmen1Val> pwmen1{}; 
        namespace Pwmen1ValC{
            constexpr Register::FieldValue<decltype(pwmen1)::Type,Pwmen1Val::em1> em1{};
            constexpr Register::FieldValue<decltype(pwmen1)::Type,Pwmen1Val::pwm> pwm{};
        }
        ///PWM mode enable for channel2.
        enum class Pwmen2Val {
            em2=0x00000000,     ///<CT16Bn_MAT2 is controlled by EM2.
            pwm=0x00000001,     ///<PWM mode is enabled for CT16Bn_MAT2.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,Pwmen2Val> pwmen2{}; 
        namespace Pwmen2ValC{
            constexpr Register::FieldValue<decltype(pwmen2)::Type,Pwmen2Val::em2> em2{};
            constexpr Register::FieldValue<decltype(pwmen2)::Type,Pwmen2Val::pwm> pwm{};
        }
        ///PWM mode enable for channel3.
        enum class Pwmen3Val {
            em3=0x00000000,     ///<CT16Bn_MAT3 is controlled by EM3.
            pwm=0x00000001,     ///<PWM mode is enabled for CT16Bn_MAT3.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,Pwmen3Val> pwmen3{}; 
        namespace Pwmen3ValC{
            constexpr Register::FieldValue<decltype(pwmen3)::Type,Pwmen3Val::em3> em3{};
            constexpr Register::FieldValue<decltype(pwmen3)::Type,Pwmen3Val::pwm> pwm{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,4),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr0{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x40010018,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr1{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x4001001c,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr2{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x40010020,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr3{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x40010024,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Cr0{    ///<Capture Register. CR is loaded with the value of TC when there is an event on the CAP input.
        using Addr = Register::Address<0x4001002c,0x00000000,0x00000000,unsigned>;
        ///Timer counter capture value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cap{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Cr1{    ///<Capture Register. CR is loaded with the value of TC when there is an event on the CAP input.
        using Addr = Register::Address<0x40010030,0x00000000,0x00000000,unsigned>;
        ///Timer counter capture value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cap{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Cr2{    ///<Capture Register. CR is loaded with the value of TC when there is an event on the CAP input.
        using Addr = Register::Address<0x40010034,0x00000000,0x00000000,unsigned>;
        ///Timer counter capture value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cap{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr0{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x40010018,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr1{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x4001001c,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr2{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x40010020,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Mr3{    ///<Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR0 matches the TC.
        using Addr = Register::Address<0x40010024,0x00000000,0x00000000,unsigned>;
        ///Timer counter match value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> match{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Cr0{    ///<Capture Register. CR is loaded with the value of TC when there is an event on the CAP input.
        using Addr = Register::Address<0x4001002c,0x00000000,0x00000000,unsigned>;
        ///Timer counter capture value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cap{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Cr1{    ///<Capture Register. CR is loaded with the value of TC when there is an event on the CAP input.
        using Addr = Register::Address<0x40010030,0x00000000,0x00000000,unsigned>;
        ///Timer counter capture value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cap{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace Ct16b1Cr2{    ///<Capture Register. CR is loaded with the value of TC when there is an event on the CAP input.
        using Addr = Register::Address<0x40010034,0x00000000,0x00000000,unsigned>;
        ///Timer counter capture value.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> cap{}; 
        ///Reserved.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
