class Bank {
public:
    vector<long long> balances;
    
    Bank(vector<long long>& balance) {
        balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if(validAcct(account1) && validAcct(account2)){
            if(balances[account1] >= money){
                balances[account1] -= money;
                balances[account2] += money;
                return true;
            }
            else return false;
        }
        else
            return false;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if(validAcct(account)){
            balances[account] += money;
            return true;
        }
        else
            return false;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if(validAcct(account)){
            if(balances[account] >= money){
                balances[account] -= money;
                return true;
            }
            else return false;
        }
        else
            return false;
    }

    bool validAcct(int account){
        if(account < balances.size() && account >= 0)
            return true;
        else
            return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
