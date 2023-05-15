typedef Bit#(26) LineAddr;
typedef Bit#(19) Tag;
typedef Bit#(7) CacheIdx;
typedef struct { Bit#(1) write; LineAddr addr; Bit#(512) data; } MainMemReq deriving (Eq, FShow, Bits, Bounded);
typedef struct { Bit#(4) word_byte; Bit#(32) addr; Bit#(32) data; } CacheReq deriving (Eq, FShow, Bits, Bounded);
typedef struct { Bit#(4) byte_en; Bit#(32) addr; Bit#(32) data; } Mem deriving (Eq, FShow, Bits);
typedef Bit#(512) MainMemResp;

typedef Bit#(32) Word;
typedef Bit#(32) Addr;


typedef enum {Ready, StartMiss, SendFillReq, WaitFillResp, WriteBack, LoadHit, StoreHit}
ReqStatus deriving (Bits, Eq);
typedef struct { Bit#(16) id; Bit#(512) data;} ReadResp deriving (Bits, Eq);



typedef Bit#(32) CacheLineAddr;
