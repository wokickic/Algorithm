from collections import deque

def solution(board, moves):
    answer = 0
    st = deque()

    for x in moves:
        x = x - 1
        doll = 0
        for y in range(len(board)):
            if board[y][x] == 0:
                continue
            else:
                doll = board[y][x]
                board[y][x] = 0
                break
        if (doll == 0): continue
        if (len(st) == 0):
            st.append(doll)
        else:
            if st[-1] == doll:
                answer = answer + 2
                st.pop()
            else:
                st.append(doll)

    return answer