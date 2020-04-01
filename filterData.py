import pandas as pd

df = pd.read_csv("movies_metadata.csv",encoding= 'unicode_escape',error_bad_lines = False,skip_blank_lines=True)
# df['release_date'] = pd.to_datetime(df['release_date'], errors='coerce').apply(lambda x: x.date())
# df.fillna('')
df = df.dropna()

features = ["genres","overview","release_date","tagline","title","vote_average"]
for feature in features:
 	df[feature] = df[feature].dropna()

m = open("movieTitle.txt",'w')
for movie in df["title"]:
	m.write(movie.lower()+"\n")

d = open("movieDate.txt",'w')
for date in df["release_date"]:
	d.write(date+"\n")

t = open("movieTag.txt",'w')
for tag in df["tagline"]:
	t.write(tag+"\n")

v = open("movieVote.txt",'w')
for vote in df["vote_average"]:
	v.write(str(vote)+"\n")

# print(type(df["genres"]))

# print(df.head(5))
print(df["overview"])
print(df["release_date"])
print(df["title"])
print(df["tagline"])
print(df["vote_average"])


