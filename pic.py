import matplotlib.pyplot as plt
Type = []
X = []
Y = []
path = 'map.txt'
count=0

with open(path) as f:
    for line in f.readlines():
        count+=1
        s = line.split(' ')
        Type.append(int(s[0]))
        X.append(float(s[1]))
        Y.append(float(s[2]))
fig=plt.figure()

ax=fig.add_subplot(1,1,1);
for i in range(0,count):
    if Type[i]==0:
        ax.scatter(X[i],Y[i],color='olive')
    elif Type[i]==1:
        ax.scatter(X[i],Y[i],color='lightskyblue')
    elif Type[i]==2:
        ax.scatter(X[i],Y[i],color='navy')
    elif Type[i]==3:
        ax.scatter(X[i],Y[i],color='seagreen')
    elif Type[i]==4:
        ax.scatter(X[i],Y[i],color='purple')
    elif Type[i]==5:
        ax.scatter(X[i],Y[i],color='pink')
    elif Type[i]==6:
        ax.scatter(X[i],Y[i],color='slategrey')
    elif Type[i]==7:
        ax.scatter(X[i],Y[i],color='lightsalmon')
    elif Type[i]==8:
        ax.scatter(X[i],Y[i],color='r')

							
ax.legend(['Store'])
ax.set_title('MAP')
plt.show();
