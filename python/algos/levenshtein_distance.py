def levenshtein_distance(s1, s2):
    l1, l2 = len(s1), len(s2)
    prev_row, curr_row = [i for i in range(l2+1)], [0]*(l2+1)
    for i in range(1, l1+1):
        curr_row[0] = i
        for j in range(1, l2+1):
            if s1[i-1] == s2[j-1]:
                curr_row[j] = prev_row[j-1]
            else:
                curr_row[j] = 1+min(curr_row[j-1], prev_row[j], prev_row[j-1])
        prev_row = curr_row.copy()
    return curr_row[l2]


