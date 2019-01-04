for(int i=0;i<v.size() && rem;i++)
        {
            while(v[i]>0 && rem){
                v[i]--;
                v.pb(v[i]);
                rem--;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<(1<<v[i])<<" ";
        }