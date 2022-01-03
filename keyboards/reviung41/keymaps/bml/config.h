#pragma once

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 175

#define TAPPING_TERM_PER_KEY

// Read "a guide to homerow mods" for info regarding the next defines for holds,taps, etc
// https://precondition.github.io/home-row-mods#toc-skipped

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
