
d = {1:{'sub_str':'', 'length':1, 'mod_increment':0, 'pi':0},
     2:{'sub_str':'abc', 'length':3, 'mod_increment':0, 'pi':0},
     3:{'sub_str':'def', 'length':3, 'mod_increment':0, 'pi':0},
     4:{'sub_str':'ghi', 'length':3, 'mod_increment':0, 'pi':0},
     5:{'sub_str':'jkl', 'length':3, 'mod_increment':0, 'pi':0},
     6:{'sub_str':'mno', 'length':3, 'mod_increment':0, 'pi':0},
     7:{'sub_str':'pqrs', 'length':4, 'mod_increment':0, 'pi':0},
     8:{'sub_str':'tuv', 'length':3, 'mod_increment':0, 'pi':0},
     9:{'sub_str':'wxyz', 'length':4, 'mod_increment':0, 'pi':0}}

digits = "22"
total = 1
tdlen = 1

for digit in digits:
    d_info = d[int(digit)]
    d_info['mod_increment'] = tdlen
    tdlen = tdlen * d_info['length']
    total = total * d_info['length']

print(d)
all_strings = [] 
for i in range(0, total):
    ss = ""
    for digit in digits:
        sss = d[int(digit)]
        # Deal with the special case of digit 1 having no letters
        if sss['length'] == 1:
            continue

        if sss['mod_increment'] == 1:
            sss['pi'] = i % sss['length']
            print("{}{}: pi:{} ++".format(i, digit, sss['pi']))
        elif i % sss['mod_increment'] == 0:
            sss['pi'] = (sss['pi'] + 1) % sss['length']
            print("{}{}: pi:{} ++d".format(i, digit, sss['pi']))

        else:
            print("{}{}: pi:{}".format(i, digit, sss['pi']))
        ss = ss + sss['sub_str'][sss['pi']]

    # print(ss)
    all_strings.append(ss)

print(all_strings)
