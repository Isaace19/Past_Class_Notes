
import random
import string

# generate a random name for the test
def randomword(length):
    return ''.join(random.choice(string.ascii_letters) for i in range(length))

# generate a list of rolls for each frame
def gen_frames(length):
    l = []
    for i in range(length):
        roll_one = random.randint(0, 10)
        l.append(roll_one)
        
        # skip iteration if roll_one is 10
        if roll_one == 10:
            continue
        
        roll_two = random.randint(0, 10 - roll_one)
        l.append(roll_two)

    return l        

def gen_tenth_frame():
    l = []
    # roll one
    l.append(random.randint(0,10))
    # roll two
    l.append(random.randint(0,10-l[0]))

    # roll three
    if l[0] + l[1] >= 10:
        l.append(random.randint(0,10))    

    return l            
        
def main():
    # write random word to file
    with open('test.txt', 'w') as f:
        for num in range(5):
            f.write(randomword(10)+'\n')

            # write each element of generate test on a new line
            for i in gen_frames(9):
                f.write(f'{i}\n')
            
            # write third frame
            for i in gen_tenth_frame():
                f.write(f'{i}\n')

        f.write('done\n')
    
if __name__ == '__main__':
    main()
