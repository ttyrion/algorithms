namespace algorithm {
    namespace find{
        /**
         * @p  the pattern string when doing string match
         * @return the next array of the pattern string p, 
         *         it should be deleted out of use if not null.
        */
        int* kmp_get_next(const char *p);
        int kmp_find_first_of(const char *str, const char *pattern);
    }
}