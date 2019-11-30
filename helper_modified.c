// Name: Keyu Man
// Student ID #: 862113727
#include <unistd.h>
#include "mcfutil.h"
#include "helper.h"
#include <stdint-gcc.h>

uint32_t program_counter;
uint32_t program_counter1;
uint32_t good_threads = 0;
uint32_t wait_counter = 0;

void helper_thread_sync()
{
    program_counter++;
    return;
}

void *helper_thread(void *x) {
    uint32_t helper_counter = program_counter1;
    node_t* node = ((node_t*)x)->child;
    node_t* tmp = node;
    uint32_t local_counter = 0;
    while( node != (node_t*)x ) {
        while (node) {
            tmp = node;
            //struct arc* nouse2 = node->basic_arc;
            cost_t nouse1 = node->basic_arc->cost;
            struct node* nouse3 = node->pred;
            cost_t nouse = node->potential;
            node = node->child;
            local_counter++;
//            if (local_counter == 5000) {
//                helper_counter += local_counter;
//                local_counter = 0;
//                while (helper_counter > program_counter + 10000) {
//                    usleep(1);
//                    wait_counter++;
//                }
//                if (helper_counter < program_counter) {
//                    //printf("%d, %d\n", helper_counter, program_counter);
//                    return NULL;
//                }
//            }

        }
        if (helper_counter +local_counter < program_counter) {
            //printf("%d, %d\n", helper_counter, program_counter);
            return NULL;
        }


        node = tmp;
        while( node->pred ) {
            node_t* temp = node->pred;
            tmp = node->sibling;
            if (!tmp)
                node = temp;
            else {
                node = tmp;
                break;
            }
            local_counter++;
        }

    }
//    if (local_counter + helper_counter > program_counter1 + 20000)
//    printf("%d\n", local_counter + helper_counter - program_counter1);
//    good_threads++;
    return NULL;
}
