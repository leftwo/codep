#include <stdio.h>
#include <stdbool.h>

enum states { START, LSPACE, NEG, PLUS, DIGIT_ONE,
    DOT, DIGIT_TWO, E, NEG_E, PLUS_E, DIGIT_THREE, TSPACE, DONE };

const char *
state_to_str(enum states s)
{
    switch (s) {
        case START: return ("START");
        case LSPACE: return ("LSPACE");
        case NEG: return ("NEG");
        case PLUS: return ("PLUS");
        case DIGIT_ONE: return ("DIGIT_ONE");
        case DOT: return ("DOT");
        case DIGIT_TWO: return ("DIGIT_TWO");
        case E: return ("E");
        case NEG_E: return ("NEG_E");
        case PLUS_E: return ("PLUS_E");
        case DIGIT_THREE: return ("DIGIT_THREE");
        case TSPACE: return ("TSPACE");
        case DONE: return ("DONE");
        default: return ("?");
    }
    return ("Not reached");
}

typedef struct st_map {
    enum states s;
    enum states *from;
} st_map_t;

enum states       START_FROM[] = { START };
enum states      LSPACE_FROM[] = { START, LSPACE };
enum states         NEG_FROM[] = { START, LSPACE };
enum states        PLUS_FROM[] = { START, LSPACE };
enum states   DIGIT_ONE_FROM[] = { START, LSPACE, NEG, PLUS, DIGIT_ONE};
enum states         DOT_FROM[] = { START, LSPACE, NEG, PLUS, DIGIT_ONE};
enum states   DIGIT_TWO_FROM[] = { DOT, DIGIT_TWO};
enum states           E_FROM[] = { DIGIT_ONE, DIGIT_TWO};
enum states       NEG_E_FROM[] = { E };
enum states      PLUS_E_FROM[] = { E };
enum states DIGIT_THREE_FROM[] = { E, NEG_E, PLUS_E, DIGIT_THREE};
enum states  TSPACE_FROM[] = { DIGIT_ONE, DOT, DIGIT_TWO, DIGIT_THREE, TSPACE};
enum states    DONE_FROM[] = { DIGIT_ONE, DOT, DIGIT_TWO, DIGIT_THREE, TSPACE};

bool isNumber(char* s) {
    enum states st = START;
    bool res = false;

    while (*s) {
        if (*s == ' ') {
            switch (st) {
                case START:
                case LSPACE:
                    st = LSPACE;
                    break;
                case DIGIT_ONE:
                case DOT:
                case DIGIT_TWO:
                case DIGIT_THREE:
                case TSPACE:
                    st = TSPACE;
                    break;
                default:
                    return (false);
            }
        } else if (*s == '-') {
            switch (st) {
                case START:
                case LSPACE:
                    st = NEG;
                    break;
                case E:
                    st = NEG_E;
                    break;
                default:
                    return (false);
            }
        } else if (*s == '+') {
            switch (st) {
                case START:
                case LSPACE:
                    st = PLUS;
                    break;
                case E:
                    st = PLUS_E;
                    break;
                default:
                    return (false);
            }
        } else if (*s == '.') {
            switch (st) {
                case START:
                case LSPACE:
                case NEG:
                case PLUS:
                case DIGIT_ONE:
                    st = DOT;
                    break;
                default:
                    return (false);
            }
        } else if (*s >= '0' && *s <= '9') {
            switch (st) {
                case START:
                case LSPACE:
                case NEG:
                case PLUS:
                case DIGIT_ONE:
                    res = true;
                    st = DIGIT_ONE;
                    break;
                case DOT:
                case DIGIT_TWO:
                    res = true;
                    st = DIGIT_TWO;
                    break;
                case E:
                case NEG_E:
                case PLUS_E:
                case DIGIT_THREE:
                    st = DIGIT_THREE;
                    break;
                default:
                    return (false);
            }
        } else if (*s == 'e') {
            switch (st) {
                case DIGIT_ONE:
                case DOT:
                case DIGIT_TWO:
                    st = E;
                    break;
                default:
                    return (false);
            }
        } else {
            return (false);
        }
        s = s + 1;
    }
    /*
     * In order to be true, we have to have had at least one digit
     * somewhere in our history.  If we do find one, we flip res to true.
     */
    switch (st) {
        case DIGIT_ONE:
        case DIGIT_TWO:
            return (true);
        case DOT:
        case DIGIT_THREE:
        case TSPACE:
            return (res);
        default:
            return (false);
    }
    return (res);
}

static void
ttt(char *str)
{
    bool res;
    res = isNumber(str);
    printf("%s is %s\n", str, res ? "true" : "false");
}

static void
tttest(char *str, bool exp_res, int id)
{
    bool res;
    res = isNumber(str);
    if (res != exp_res) {
        printf("'%s' FAILED, expected %s got %s\n",
            str, exp_res ? "true" : "false", res ? "true" : "false");
    // } else {
    //    printf("'%s' got expected result %s\n", str, res ? "true" : "false");
    }
}

typedef struct tests {
    char *str;
    bool res;
} test_t;

test_t mytest[] = {
   { "0", true },
   { "0.1", true },
   { "1 a", false },
   { "2e10", true },
   { " 2e10", true },
   { "   2e10", true },
   { " 2e10 ", true },
   { "  2e10 ", true },
   { "2e10   ", true },
   { "2e10 ", true },
   { "2e10  ", true },
   { "43.2e10", true },
   { "e", false },
   { "e23", false },
   { "abc", false },
   { "e.44", false },
   { "432e45.5", false },
   { "432.45.5", false },
   { "432e45.5", false },
   { "e4e", false },
   { "e4", false },
   { "5e4e", false },
   { " e", false },
   { ".", false},
   { " .", false},
   { " . ", false},
   { ". 1", false},
   { "1 .", false},
   { "1 e10", false},
   { "45. ", true},
   { "45.", true},
   { " 45. ", true},
   { ".45 ", true},
   { ".45", true},
   { " .45 ", true},
   { " 99e4 ", true},
   { "99e ", false},
   { "99e 4", false},
   { "123 456", false},
   { " 456 ", true},
   { " ", false },
   { "", false },
   { "-0", true },
   { "-0.1", true },
   { "-1 a", false },
   { "-2e10", true },
   { " -2e10", true },
   { "-2e10 ", true },
   { "-43.2e10", true },
   { "  -43.2e10", true },
   { "-e", false },
   { "-e23", false },
   { "-abc", false },
   { "-e.44", false },
   { "-432e45.5", false },
   { "-432.45.5", false },
   { "-432e45.5", false },
   { "-e4e", false },
   { "-e4", false },
   { "-5e4e", false },
   { "- e", false },
   { " -e", false },
   { ".-", false},
   { "-", false},
   { " -.", false},
   { " -. ", false},
   { "-. 1", false},
   { "-1 .", false},
   { "-1 e10", false},
   { "-45. ", true},
   { "-4.e5 ", true},
   { "-4.e5", true},
   { "-45.", true},
   { " -45. ", true},
   { "-.45", true},
   { "-.45 ", true},
   { " -.45 ", true},
   { " -99e4 ", true},
   { "-99e ", false},
   { "-99e 4", false},
   { "-123 456", false},
   { " -456 ", true},
   { " -", false },
   { "+.8", true },
   { "+8", true },
   { "+8e8", true },
   { "+8e+8", true },
   { "+8e-8", true },
   { "+8e-.8", false },
   { "+8e+.8", false },
   { "+.8e+8", true },
   { "++.8e+8", false },
   { "+.e8", false },
   { "+.", false },
   { " +.", false },
   { " +", false },
   { "-", false }
};

int mytest_count = sizeof(mytest) / sizeof(mytest[1]);

int
main (int argc, char *argv[])
{
    if (argc > 1) {
        ttt(argv[1]);
        return (0);
    }


    for (int i = 0; i < mytest_count; i++) {
        tttest(mytest[i].str, mytest[i].res, i);
    }

    return (0);
}
