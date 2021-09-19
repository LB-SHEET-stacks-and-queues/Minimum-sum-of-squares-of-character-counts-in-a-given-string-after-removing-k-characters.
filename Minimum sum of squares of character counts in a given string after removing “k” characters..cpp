class Solution{
public:
    int minValue(string s, int k)
    {
        // code here
        int ans=0;
        
        //ref --> Aditya Rajiv
        //minimum nikaalne ke liye aise chars hatao jo sabse jyada repeat hue ho
        
        //corner case
        int l = s.length();
 
    // if K is greater than length of string so reduced string will become 0
    if (k >= l)
        return 0;
     
    //maintain a hash, take an array hash for simplicity. Varna map liya hota to
    //it.first it.second se bohot problem hui hoti
    
    int frequency[26] = { 0 };
    
    for (int i = 0; i < l; i++)
        frequency[s[i] - 'a']++;
        
    //we now use priority queue bcoz hame highest frequency wala char har baar pta hona chaiye
    // Push each char frequency into a priority_queue
    priority_queue<int> q;
    
    for (int i = 0; i < 26; i++)
    {
        //jab character hai hi nhi to push karke matlab hi nhi
        if(frequency[i]!=0)
        {
            q.push(frequency[i]);
        }
    }
    
    //ab k operations karke highest frequency wale char ko baar baar reduce karte jao
    while(k>0)
    {
        //highest freq wale element ko kam karte karte waapis add karo queue me
        
        int top=q.top();
        q.pop();
        top--;
        k--;
        q.push(top);
    }
    
    //ab square count karo
    while(q.empty()==false)
    {
        int top=q.top();
        ans=ans+(top*top);
        q.pop();
    }
      
      return ans;
        
    }
};
