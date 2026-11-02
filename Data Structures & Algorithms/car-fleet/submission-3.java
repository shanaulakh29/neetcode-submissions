class Pair<K, V>{
    K first;
    V second;
    Pair(K first, V second){
        this.first = first;
        this.second = second;
    }
}
class customComparator implements Comparator<Pair<Integer, Integer>>{
    public int compare(Pair<Integer, Integer>a, Pair<Integer, Integer>b){
        if(a.first>b.first){
            return -1;
        }else if(a.first<b.first){
            return 1;
        }else{
            return 0;
        }
    }
}
class Solution {
    
    public int carFleet(int target, int[] position, int[] speed) {
        List<Pair<Integer, Integer>>list = new ArrayList<>();
        for(int i=0;i<position.length;i++){
            list.add(new Pair(position[i], speed[i]));
        }
        Collections.sort(list, new customComparator());
        Deque<Pair<Integer, Integer>>stack = new ArrayDeque<>();
        for(int i=0;i<list.size();i++){
            if(stack.isEmpty()){
                stack.push(list.get(i));
            }else{
                int pos = stack.peek().first;
                int sp = stack.peek().second;
                double time1 = (double)(target - pos)/sp;
                double time2 = (double)(target - list.get(i).first)/list.get(i).second;
                if(time2<=time1){
                    continue;
                }
                stack.push(list.get(i));
            }
        }
        return stack.size();
    }
}
