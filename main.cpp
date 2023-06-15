#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

struct data
{
    string product_name,product_code;
    float product_price,tax,final_price,total_price;
    int quantity;

};

 float tax_value(float product_price,float tax_percentage)
 {
     float tax_value=product_price*(tax_percentage/100);
    return tax_value;
 };

int main()
{
    bool repeat =false;
    do{
     int n,m,raw,col,q,served_orders=1;
     float total_amount=0,Total_Amount_of_all_orders=0;

     cout<< "Please Enter Number of available products in the market:  ";
     cin>>n;
     string arr1[n][2];
     float arr2[n][2];


    for (int i=0;i<n;i++)
    {

             cout<< "Please Enter product name, code, price and tax:  "<<endl;
             cin>>arr1[i][0]>>arr1[i][1]>>arr2[i][0]>>arr2[i][1];
             cout<<endl;
    };



    cout<< "Now we are ready to accept orders"<<endl<<endl;
    cout<< "Please Enter number of products in the order:  "<<endl;
    cin>> m;
    data products[m];

    string find_index;

    for(int k=0;k<m;k++)
    {

       cout<< "Please enter product code and quantity:   "<<endl ;
       cin>>find_index>>q;
          for (int i=0;i<n;i++)
        {
            for (int j=0;j<2;j++)
          {
            if(find_index==arr1[i][j])
            {
            raw=i,col=j;
            break;
            }
          }

        };


    products[k].product_name=arr1[raw][col-1];
    products[k].product_code=arr1[raw][col];
    products[k].product_price=arr2[raw][col-1];
    products[k].tax=tax_value(products[k].product_price,arr2[raw][col]);
    products[k].quantity=q;
    products[k].final_price=products[k].product_price+products[k].tax;
    products[k].total_price=products[k].final_price*products[k].quantity;
    total_amount+=products[k].total_price;

    };
         Total_Amount_of_all_orders+=total_amount;

    cout<< setw(15)<<"product name"<<setw(8)<< "price"<<setw(6)<<"tax"<<setw(14)<<"final price"<<setw(11)<<"quantity"<<setw(14)<<"total price"<<endl;

     for(int i=0;i<m;i++)
     {
    cout<<" "<<setw(14)<<products[i].product_name<<setw(6)<<products[i].product_price<<setw(7)<<products[i].tax<<setw(10)<<products[i].final_price<<setw(13)<<products[i].quantity<<setw(13)<<products[i].total_price<<endl;
     };
     cout<< "total amount:  "<< total_amount<<endl;
     string answer;
     cout<< "Do you want to start a new order? (yes), (no)"<<endl;
     cin>>answer;
     cout<<endl<<endl;
     if(answer=="yes")
      {
        repeat=true;
        served_orders+=1;
      }
     else
      {
        cout<< "Number of served orders is:  "<<served_orders<<endl;
        cout<< "Total Amount of all orders is:   "<<Total_Amount_of_all_orders<<endl<<endl;
        cout<< "Good By ^_^"<<endl<<endl;
      };
    } while(repeat);

    return 0;
}






