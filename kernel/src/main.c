char* video_memory = (char*) 0xb8000;

void print() {
    *(video_memory+2) = '+';
    *(video_memory+3) = 0x0B;
}

void _kentry() {
    *video_memory = 'K';
    *(video_memory+1) = 0x0B;
    print();
    return;
}