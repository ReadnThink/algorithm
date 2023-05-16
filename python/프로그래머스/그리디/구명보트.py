def solution(people, limit):
    answer = 0
    people.sort()
    
    left, right = 0, len(people) -1
    while left <= right:
        wight = people[left] + people[right]
        if wight <= limit:
            left += 1
            right -= 1
        else:
            right -= 1
        answer += 1
        
    return answer