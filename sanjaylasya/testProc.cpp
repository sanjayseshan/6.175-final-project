#include "TopIndication.h"
#include "TopRequest.h"
#include "elf2hex/ElfLoader.hpp"

#define ELF_SIZE (1 << 29)

sem_t finish_sem;
sem_t read_sem;
uint32_t value = 0;

class TopIndication : public TopIndicationWrapper
{
public:
    TopIndication(unsigned int id) : TopIndicationWrapper(id){};

    virtual void returnResult(uint32_t tick, uint32_t res) {
        fprintf(stderr, "%d: Returned result %d\n", tick, res);
        sem_post(&finish_sem);
    }

    virtual void printChar(uint32_t tick, uint8_t c) {
        fprintf(stderr, "%c", (char)c);
    }

    virtual void printInt(uint32_t tick, uint32_t i) {
        //fprintf(stderr, "%d: Got write resp for id %x\n", tick, i);
    }

    virtual void error(uint32_t code, uint32_t data) {
        fprintf(stderr, "AxiError code %d: %d\n", code, data);
        sem_post(&finish_sem);
    }
    virtual void currentPc(uint32_t tick, uint32_t pc) {
        //fprintf(stderr, "%d: PC: %x\n", tick, pc);
    }
    virtual void logMemReq(uint32_t tick, int write, uint32_t addr, uint32_t data) {
        //fprintf(stderr, "%d: %s at addr %x, data %x\n", tick, (write ? "store" : "load"), addr, data);
    }
    virtual void logMemResp(uint32_t tick, uint32_t id, uint32_t data) {
        //fprintf(stderr, "%d: mem resp from addr %x: %x\n", tick, id, data);
    }
    virtual void reportDeadlock(uint32_t tick, uint32_t pc0, uint32_t pc1, uint32_t pc2) {
        //fprintf(stderr, "%d: deadlock at pc's %x, %x, %x\n", tick, pc0, pc1, pc2);
    }
    virtual void logCacheReq(uint32_t tick, int fromCache, uint32_t addr, int valid, uint32_t data) {
        //fprintf(stderr, "%d: queuing into cacheOut: fromCache %d, addr %x, addReq valid %d, data %x\n", tick, fromCache, addr, valid, data);
    }
};


int main(int argc, const char **argv)
{
    TopRequestProxy *topRequest = new TopRequestProxy(IfcNames_TopRequestS2H);
    TopIndication topIndication(IfcNames_TopIndicationH2S);
    if (sem_init(&finish_sem, 1, 0)){
        fprintf(stderr, "failed to init finish_sem\n");
        return -1;
    }

    size_t buf_sz = (1 << 16); //64kb buffer, if program doesn't fit in buffer just up this number
    char* elf_buf = (char*)malloc(buf_sz);
    if (!load_elf(argv[1], elf_buf, buf_sz)){
        fprintf(stderr, "failed to load elf\n");
        return -1;
    }
    uint32_t* buf = (uint32_t*) elf_buf;
    for (uint32_t i = 0; i < buf_sz; i += 64) {
        uint32_t s = i >> 2;
        topRequest->loadMem(i, buf[s], buf[s+1], buf[s+2], buf[s+3], buf[s+4],
                            buf[s+5], buf[s+6], buf[s+7], buf[s+8],
                            buf[s+9], buf[s+10], buf[s+11], buf[s+12],
                            buf[s+13], buf[s+14], buf[s+15]);
        if ((i & 0x0003FFFF) == 0) fprintf(stderr, "%d MB loaded\n", s >> 20);
    }
    fprintf(stderr, "starting program\n");
    topRequest->startProc();
    sem_wait(&finish_sem);
    return 0;
}
