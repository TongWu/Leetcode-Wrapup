import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    view_own = views[views['author_id'] == views['viewer_id'] ]
    result = view_own['author_id'].unique()
    result = sorted(result)
    return pd.DataFrame({'id': result})