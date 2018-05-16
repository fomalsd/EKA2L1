#pragma once

#include <arm/jit_interface.h>
#include <unicorn/unicorn.h>

namespace eka2l1 {
    namespace arm {
        class jit_unicorn : public jit_interface {
            uc_engine *engine;
            address epa;

        private:
            bool execute_instructions(int num_instructions);

        public:
            jit_unicorn();
            ~jit_unicorn();

            void run() override;
            void stop() override;

            void step() override;

            uint32_t get_reg(size_t idx) override;
            uint64_t get_sp() override;
            uint64_t get_pc() override;
            uint64_t get_vfp(size_t idx) override;

            void set_reg(size_t idx, uint32_t val) override;
            void set_pc(uint64_t val) override;
			void set_sp(uint32_t val) override;
            void set_lr(uint64_t val) override;
            void set_vfp(size_t idx, uint64_t val) override;

            uint32_t get_cpsr() override;

            void save_context(thread_context &ctx) override;
            void load_context(const thread_context &ctx) override;

            void set_entry_point(address ep) override;
            address get_entry_point() override;

            void set_stack_top(address addr) override;
            address get_stack_top() override;

			void prepare_rescheduling();
        };
    }
}
