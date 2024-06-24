## Welcome to Watch It

**Description:**
Watch It is structured around six primary entities to manage and track movie-related data efficiently:

1. **User:** Each user has a unique ID, username, password, and personal details. Users can subscribe to various plans, bookmark movies for later viewing, and keep a record of watched movies.
2. **Subscription:** Subscriptions are divided into Basic, Standard, and Premium plans, each with its pricing and start date.
3. **Movie:** Movies have several attributes, including ID, title, release date, duration, cast, genres, director, language, IMDb score, country, budget, revenue, and poster image.
4. **Cast:** Actors in the movies are detailed with their first name, last name, age, gender, list of movies, and nationality.
5. **Director:** Directors are described with their first name, last name, age, gender, list of movies, and nationality.
6. **User Watch Record:** This entity tracks users' movie-watching activities, including the date watched and user ratings.

**Constraints:**
Subscriptions are valid for 30 days. Users on Basic, Standard, or Premium plans have specific limits on the number of movies they can watch per month. After 30 days, users must renew their subscription to continue watching movies.

**Functionalities:**

1. **CRUD Operations:** Users can create, update, and delete entities like movies, subscriptions, and watch records.
2. **View Watchlist:** Users can view a list of movies marked for later viewing.
3. **View Watch History:** Users can see all the movies they have watched.
4. **Movie Rating Update:** Movie ratings are updated based on user watch records.
5. **Top-Rated Movies:** Users can view the highest-rated movies based on user ratings.
6. **Subscription Analysis:** Admins can view the most popular subscription plan among Basic, Standard, and Premium.
7. **Revenue Analysis:** Admins can analyze revenue trends by summing up plan prices subscribed in a month.
8. **View Cast and Directors:** Users can access information about cast members and directors.
9. **Search Functionality:** Users can search for movies, directors, and actors by name.
10. **Genre Search:** Users can search for and display movies by genre.
11. **Top Watched Movies:** Users can see the most-watched movies.
12. **Recent Movies:** Users can explore recently released movies.

**About:**
Watch It is a console-based software application providing access to an extensive library of movies. With a wide variety of genres, Watch It caters to diverse tastes and preferences, ensuring a seamless streaming experience. The application is developed in Java and employs Object-Oriented Programming principles.
