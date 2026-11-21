int _kentry() {
    char* video_memory = (char*) 0xb8000;
    *video_memory = 'K';
    *(video_memory+1) = 0x0B;
}