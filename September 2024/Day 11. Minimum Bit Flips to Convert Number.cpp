class Solution {
    public int minBitFlips(int start, int goal) {
        int count = 0;
        for(int i=0; i<31; i++){
            if(((start>>i)&1) != ((goal>>i)&1))
                count++;
        }
        return count;
    }
}
