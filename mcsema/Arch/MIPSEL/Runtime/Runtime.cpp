
#include <cstdio>
#include <cfenv>
#include <cfloat>
#include <inttypes.h>
#include <cstdint> //needed for uint16_t

// #define HAS_FEATURE_AVX 1
// #define HAS_FEATURE_AVX512 0
// #define ADDRESS_SIZE_BITS 64

// !!! RULES FOR STATE STRUCTURE TYPES !!!
//
//  (1) Never use a type that has a different allocation size on a different
//      architecture. This includes things like pointers or architecture-
//      specific floating point types (e.g. `long double`).
//
//  (2) Never depend on implicit padding or alignment, even if you explicitly
//      specify it. Always "fill" structures to the desired alignment with
//      explicit structure fields.
//
//  (3) Trust but verify the `static_assert`s that try to verify the sizes of
//      structures. Clang will LIE to you! This happens if you compile a file
//      to bitcode for one architecture, then change its `DataLayout` to
//      match another architecture.


#include "remill/Arch/MIPSEL/Runtime/State.h"
#include "mcsema/Arch/MIPSEL/Runtime/Registers.h"


// #ifndef PRIx64
// # define PRIx64 "llxx"
// #endif

#ifndef PRIx32
# define PRIx32 "x"
#endif

extern "C" {

// Debug registers [ unverified ]
uint32_t DEBUG;
uint32_t DEPC;
uint32_t DESAVE;
/* need to add support for cp0-cp3 coprecessor for use them */
// for FPU, add CP1 support


// TODO:
//add Debug and control register

Memory *__mcsema_reg_tracer(State &state, addr_t, Memory *memory) {

  #define PRIx64 "x" //warning suppressor
  // #define PRIx32 "x"
  const char *format = nullptr;
  if (sizeof(void *) == 8) { 
  
  // if any error occurs, simply print the registors values
  // to the stderr, so they can be debugged later.
  
    /* for 64 bit systems only
     for now, mapped back to 32 bit equivalent 
     in Register.h
     throws some warning, ignore them
    */
    fprintf(
        stderr,
        "RIP=%" PRIx64 ",RAX=%" PRIx64 ",RBX=%" PRIx64
        ",RCX=%" PRIx64 ",RDX=%" PRIx64 ",RSI=%" PRIx64
        ",RDI=%" PRIx64 ",RBP=%" PRIx64 ",RSP=%" PRIx64
        ",R8=%" PRIx64 ",R9=%" PRIx64 ",R10=%" PRIx64
        ",R11=%" PRIx64 ",R12=%" PRIx64 ",R13=%" PRIx64
        ",R14=%" PRIx64 ",R15=%" PRIx64 "\n",

         state.RIP, state.RAX, state.RBX, state.RCX, state.RDX, state.RSI,
         state.RDI, state.RBP, state.RSP, state.R8, state.R9, state.R10,
         state.R11, state.R12, state.R13, state.R14, state.R15);
  } else {
    // do not start with "zero"
    //void * on mips?? [qemu-xompiler says 4, but check again with qemu kvm]
    fprintf(
        stderr,
        "pc=%" PRIx32 ",at=%" PRIx32 ",v0=%" PRIx32
        ",v1=%" PRIx32 ",a0=%" PRIx32 ",a1=%" PRIx32
        ",a2=%" PRIx32 ",sp=%" PRIx32 ",fp=%" PRIx32 "\n",
        state.gpr.ra.word, state.gpr.at.word, state.gpr.v0.word, state.gpr.v1.word, state.gpr.a0.word, state.gpr.a1.word,
        state.gpr.a2.word, state.gpr.sp.word, state.gpr.fp.word);
  }
  return memory;
}

// Read/write to I/O ports.
uint8_t __remill_read_io_port_8(Memory *, addr_t) {
  abort();
}

uint16_t __remill_read_io_port_16(Memory *, addr_t) {
  abort();
}

uint32_t __remill_read_io_port_32(Memory *, addr_t) {
  abort();
}

Memory *__remill_write_io_port_8(Memory *, addr_t, uint8_t) {
  abort();
}

Memory *__remill_write_io_port_16(Memory *, addr_t, uint16_t) {
  abort();
}

Memory *__remill_write_io_port_32(Memory *, addr_t, uint32_t) {
  abort();
}

// Memory read intrinsics.
uint8_t __remill_read_memory_8(Memory *, addr_t addr) {
  return *reinterpret_cast<uint8_t *>(addr);
}

uint16_t __remill_read_memory_16(Memory *, addr_t addr) {
  return *reinterpret_cast<uint16_t *>(addr);
}

uint32_t __remill_read_memory_32(Memory *, addr_t addr) {
  return *reinterpret_cast<uint32_t *>(addr);
}

uint64_t __remill_read_memory_64(Memory *, addr_t addr) {
  return *reinterpret_cast<uint64_t *>(addr);
}

// Memory write intrinsics.
Memory *__remill_write_memory_8(
    Memory * memory, addr_t addr, uint8_t val) {
  *reinterpret_cast<uint8_t *>(addr) = val;
  return memory;
}

Memory *__remill_write_memory_16(
    Memory * memory, addr_t addr, uint16_t val) {
  *reinterpret_cast<uint16_t *>(addr) = val;
  return memory;
}

Memory *__remill_write_memory_32(
    Memory * memory, addr_t addr, uint32_t val) {
  *reinterpret_cast<uint32_t *>(addr) = val;
  return memory;
}

Memory *__remill_write_memory_64(
    Memory * memory, addr_t addr, uint64_t val) {
  *reinterpret_cast<uint64_t *>(addr) = val;
  return memory;
}

float32_t __remill_read_memory_f32(
    Memory *, addr_t addr, float32_t val) {
  return *reinterpret_cast<float32_t *>(addr);
}

float64_t __remill_read_memory_f64(
    Memory *, addr_t addr, float64_t val) {
  return *reinterpret_cast<float64_t *>(addr);

}

float64_t __remill_read_memory_f80(Memory *, addr_t addr) {
  return static_cast<float64_t>(*reinterpret_cast<long double *>(addr));
}

Memory *__remill_write_memory_f32(
    Memory * memory, addr_t addr, float32_t val) {
  *reinterpret_cast<float32_t *>(addr) = val;
  return memory;
}

Memory *__remill_write_memory_f64(
    Memory * memory, addr_t addr, float64_t val) {
  *reinterpret_cast<float64_t *>(addr) = val;
  return memory;
}

Memory *__remill_write_memory_f80(
    Memory * memory, addr_t addr, float64_t val) {
  *reinterpret_cast<long double *>(addr) = static_cast<long double>(val);
  return memory;
}

// Memory barriers types, see: http://g.oswego.edu/dl/jmm/cookbook.html
Memory *__remill_barrier_load_load(Memory * memory) {
  return memory;
}

Memory *__remill_barrier_load_store(Memory * memory) {
  return memory;
}

Memory *__remill_barrier_store_load(Memory * memory) {
  return memory;
}

Memory *__remill_barrier_store_store(Memory * memory) {
  return memory;
}

// Atomic operations. The address/size are hints, but the granularity of the
// access can be bigger. These have implicit StoreLoad semantics.
Memory *__remill_atomic_begin(Memory * memory) {
  return memory;
}

Memory *__remill_atomic_end(Memory * memory) {
  return memory;
}

Memory *__remill_compare_exchange_memory_8(
    Memory *memory, addr_t addr, uint8_t &expected, uint8_t desired) {
  expected = __sync_val_compare_and_swap(
      reinterpret_cast<uint8_t *>(addr), expected, desired);
  return memory;
}

Memory *__remill_compare_exchange_memory_16(
    Memory *memory, addr_t addr, uint16_t &expected, uint16_t desired) {
  expected =  __sync_val_compare_and_swap(
      reinterpret_cast<uint16_t *>(addr), expected, desired);
  return memory;
}

Memory *__remill_compare_exchange_memory_32(
    Memory *memory, addr_t addr, uint32_t &expected, uint32_t desired) {
  expected = __sync_val_compare_and_swap(
      reinterpret_cast<uint32_t *>(addr), expected, desired);
  return memory;
}

Memory *__remill_compare_exchange_memory_64(
    Memory *memory, addr_t addr, uint64_t &expected, uint64_t desired) {
  expected = __sync_val_compare_and_swap(
      reinterpret_cast<uint64_t *>(addr), expected, desired);
  return memory;
}

#ifdef _GXX_EXPERIMENTAL_CXX0X__
Memory *__remill_compare_exchange_memory_128(
    Memory *memory, addr_t addr, uint128_t &expected, uint128_t &desired) {
  expected = __sync_val_compare_and_swap(
      reinterpret_cast<uint128_t *>(addr), expected, desired);
  return memory;
}
#endif

Memory *__remill_fetch_and_add_8(
    Memory *memory, addr_t addr, uint8_t &value) {
  value = __sync_fetch_and_add(reinterpret_cast<uint8_t*>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_add_16(
    Memory *memory, addr_t addr, uint16_t &value) {
  value =  __sync_fetch_and_add(reinterpret_cast<uint16_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_add_32(
    Memory *memory, addr_t addr, uint32_t &value) {
  value = __sync_fetch_and_add(reinterpret_cast<uint32_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_add_64(
    Memory *memory, addr_t addr, uint64_t &value) {
  value = __sync_fetch_and_add(reinterpret_cast<uint64_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_sub_8(
    Memory *memory, addr_t addr, uint8_t &value) {
  value = __sync_fetch_and_sub(reinterpret_cast<uint8_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_sub_16(
    Memory *memory, addr_t addr, uint16_t &value) {
  value =  __sync_fetch_and_sub(reinterpret_cast<uint16_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_sub_32(
    Memory *memory, addr_t addr, uint32_t &value) {
  value = __sync_fetch_and_sub(reinterpret_cast<uint32_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_sub_64(
    Memory *memory, addr_t addr, uint64_t &value) {
  value = __sync_fetch_and_sub(reinterpret_cast<uint64_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_or_8(
    Memory *memory, addr_t addr, uint8_t &value) {
  value = __sync_fetch_and_or(reinterpret_cast<uint8_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_or_16(
    Memory *memory, addr_t addr, uint16_t &value) {
  value =  __sync_fetch_and_or(reinterpret_cast<uint16_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_or_32(
    Memory *memory, addr_t addr, uint32_t &value) {
  value = __sync_fetch_and_or(reinterpret_cast<uint32_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_or_64(
    Memory *memory, addr_t addr, uint64_t &value) {
  value = __sync_fetch_and_or(reinterpret_cast<uint64_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_and_8(
    Memory *memory, addr_t addr, uint8_t &value) {
  value = __sync_fetch_and_and(reinterpret_cast<uint8_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_and_16(
    Memory *memory, addr_t addr, uint16_t &value) {
  value =  __sync_fetch_and_and(reinterpret_cast<uint16_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_and_32(
    Memory *memory, addr_t addr, uint32_t &value) {
  value = __sync_fetch_and_and(reinterpret_cast<uint32_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_and_64(
    Memory *memory, addr_t addr, uint64_t &value) {
  value = __sync_fetch_and_and(reinterpret_cast<uint64_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_xor_8(
    Memory *memory, addr_t addr, uint8_t &value) {
  value = __sync_fetch_and_xor(reinterpret_cast<uint8_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_xor_16(
    Memory *memory, addr_t addr, uint16_t &value) {
  value =  __sync_fetch_and_xor(reinterpret_cast<uint16_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_xor_32(
    Memory *memory, addr_t addr, uint32_t &value) {
  value = __sync_fetch_and_xor(reinterpret_cast<uint32_t *>(addr), value);
  return memory;
}

Memory *__remill_fetch_and_xor_64(
    Memory *memory, addr_t addr, uint64_t &value) {
  value = __sync_fetch_and_xor(reinterpret_cast<uint64_t *>(addr), value);
  return memory;
}

int __remill_fpu_exception_test_and_clear(int read_mask, int clear_mask) {
  auto except = std::fetestexcept(read_mask);
  std::feclearexcept(clear_mask);
  return except;
}


}  // extern C