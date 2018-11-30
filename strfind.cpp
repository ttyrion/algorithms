#include "strfind.h"
#include <string.h>
#include <functional>

namespace algorithm {
    namespace find{
        /**
         * @next_array partly initialized array of next, 
         *             of which the numbers of elements should be no less than the length of pattern
         * @size       numbers of elements in next_array
         * @j          the index of pattern of which we want to get the next value
         * @pattern    the pattern string we want to find
         * @return     the next value of j
        */
       #ifdef ZERO
        int get_next(int *next_array, int j, char *pattern) {
            const int pattern_len = strlen(pattern);
            /* next[0] should always be -1, it makes the pattern moves one position when missing match*/
            if(j == 0 || j >= pattern_len) {
                return -1;
            }

            if(pattern[next_array[j-1]] == pattern[j-1]) {
                return next_array[j-1] + 1;
            }
            else {
                
            }
        }

        int fill_next(int *next_array, int size, char *pattern) {
            for(int j = 0; j < size; ++j) {

            }   
        }

        int kmp_find_first_of(char *str, char *pattern) {
            const int str_len = strlen(str);
            const int pattern_len = strlen(pattern);

            int *next = new int[pattern_len];
            memset(next,0,sizeof(int) * pattern_len);
            

            int i = 0, j = 0;
            for(; i < str_len && j < pattern_len;) {
                if(str[i] == pattern[j]) {
                    ++i;
                    ++j;
                }
                else {
                    /* keep i unchanged, change j */
                    j = kmp_next(j);
                }
            }

            if(j == pattern_len) {
                return i;
            }

            return -1;
        }

        #endif

        int* kmp_get_next(const char *p) {
            const int pn = strlen(p);
            if(pn <= 0) {
                return nullptr;
            }

            int *next = new int[pn];
            next[0] = -1;

            memset(next+1, 0, sizeof(int)*(pn-1));

            /* pi must >= 2. */
            std::function<unsigned int (unsigned int)> get_next;
            get_next = [next,p,&get_next](unsigned int pi) -> unsigned int {
                if(pi <= 0) {
                    return -1;
                }

                int m = next[pi-1];

                if(p[(next[pi-1])] == p[pi-1]) {
                    return next[pi-1] + 1;
                }
                else {
                    return get_next(next[pi-1]) + 1;
                }
            };

            for(int i = 2; i < pn; ++i) {
                next[i] = get_next(i);
            } 
        }

        int kmp_find_first_of(const char *str, const char *pattern) {
            const int sn = strlen(str);
            const int pn = strlen(pattern);
            int si = 0;
            for(; si <= sn - pn; ++si) {
                int pi = 0;
                for(; pi < pn; ++pi) {
                    if(str[si+pi] != pattern[pi]) {
                        break;
                    }
                }

                /* match */
                if (pi == pn) {
                    return si;
                }
            }

            return -1;
        }
    }
}