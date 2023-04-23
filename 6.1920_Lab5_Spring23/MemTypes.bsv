typedef Bit#(26) LineAddr;
typedef struct { Bit#(1) write; LineAddr addr; Bit#(32) data; } MainMemReq deriving (Eq, FShow, Bits, Bounded);
typedef Bit#(32) MainMemResp;

typedef Bit#(32) Word;
