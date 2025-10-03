import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Data
months = ["07/2019", "08/2019", "09/2019", "10/2019", "11/2019"]
search = [50, 65, 68, 61, 62]
direct = [39, 47, 42, 54, 51]
social = [70, 80, 90, 87, 92]

# Create DataFrame
df = pd.DataFrame({
    "Months": months,
    "Search": search,
    "Direct": direct,
    "Social Media": social
})

# Bar chart setup
bar_width = 0.25
x = np.arange(len(df["Months"]))

# Plot bars
plt.figure(figsize=(10,6))
plt.bar(x - bar_width, df["Search"], width=bar_width, label="Search", color="skyblue")
plt.bar(x, df["Direct"], width=bar_width, label="Direct", color="pink")
plt.bar(x + bar_width, df["Social Media"], width=bar_width, label="Social Media", color="orange")

# Labels & title
plt.xlabel("Months")
plt.ylabel("Visitors (in thousands)")
plt.title("Visitors by web traffic sources")
plt.xticks(x, df["Months"])
plt.legend()

# Show values on bars
for i in range(len(df["Months"])):
    plt.text(x[i] - bar_width, df["Search"][i] + 1, str(df["Search"][i]), ha='center')
    plt.text(x[i], df["Direct"][i] + 1, str(df["Direct"][i]), ha='center')
    plt.text(x[i] + bar_width, df["Social Media"][i] + 1, str(df["Social Media"][i]), ha='center')

plt.tight_layout()
plt.show()
