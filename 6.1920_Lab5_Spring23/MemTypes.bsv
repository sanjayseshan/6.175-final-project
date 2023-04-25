typedef Bit#(28) LineAddr;
typedef struct { Bit#(1) write; Bit#(28) addr; Bit#(512) data; } MainMemReq deriving (Eq, FShow, Bits, Bounded);
typedef struct { Bit#(1) write; Bit#(32) addr; Bit#(32) data; } CacheReq deriving (Eq, FShow, Bits, Bounded);
typedef Bit#(512) MainMemResp;

typedef Bit#(32) Word;

typedef Bit#(32) CacheLineAddr;
