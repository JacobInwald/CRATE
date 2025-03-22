
void homebrew_memcpy(void *dst, const void *src, int length) {
    char *d, *s;
    d = (char *)dst;
    s = (char *)src;
    while(length--) {
        *d++ = *s++;
    }
}
