mvi a,ff
sta 8050
mvi a,aa
sta 8040

lda 8040
mov b,a
lda 8050
sub b
sta a560
hlt