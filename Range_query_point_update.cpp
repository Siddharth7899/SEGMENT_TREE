//Find minimum in the given range

class SGTree
{
    public :
    vector<int> seg;
    SGTree(int n){
      seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, int arr[], int n)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr, n);
        build(2 * ind + 2, mid + 1, high, arr, n);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (l > high || r < low)
        {
            return INT_MAX;
        }
        // complete overlap
        if (high <= r && low >= l)
        {
            return seg[ind];
        }
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left,right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

//Find sum over given range 
class SGTree {
  public : 
  vector<ll> seg;
  SGTree(ll n){
    seg.resize(4*n+1);
  }
  void build(ll ind,ll low,ll high,ll arr[],ll n){
     if(low==high){
       seg[ind]=arr[low];
       return;
     }
     ll mid = (low+high)/2;
     build(2*ind+1,low,mid,arr,n);
     build(2*ind+2,mid+1,high,arr,n);
     seg[ind] = seg[2*ind+1]+seg[2*ind+2];
  }
  ll query(ll ind,ll low,ll high,ll l,ll r){
    if(r<low || l>high) return 0;
    if(low>=l && high<=r) return seg[ind];
    ll mid = (low+high)/2;
    ll left = query(2*ind+1,low,mid,l,r);
    ll right = query(2*ind+2,mid+1,high,l,r);
    return (left+right);
  }
  void update(ll ind,ll low,ll high,ll i,ll val){
    if(low==high){
      seg[ind]=val;
      return;
    }
    ll mid = (low+high)/2;
    if(i<=mid) update(2*ind+1,low,mid,i,val);
    else update(2*ind+2,mid+1,high,i,val);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
  }
};
