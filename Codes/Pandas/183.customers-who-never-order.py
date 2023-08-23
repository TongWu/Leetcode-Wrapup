import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    merged = customers.merge(orders, how='left', left_on='id', right_on='customerId')
    mask = merged['customerId'].isna()
    result = merged[mask]
    result = result[['name']].rename(columns={'name': 'Customers'})
    return result