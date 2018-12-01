namespace algorithm {
    namespace find{
        /**
         * @p  the pattern string to be matched.
         * @return the next array of the pattern string p, 
         *         it should be deleted after being used if not null.
        */
        int* kmp_get_next(const char *p);

        /**
         * @str the source string in which we want to match the pattern.
         * @pattern the pattern string to be matched.
        */
        int kmp_find_first_of(const char *str, const char *pattern);
    }
}