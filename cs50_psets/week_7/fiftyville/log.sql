-- Keep a log of any SQL queries you execute as you solve the mystery.

-- select transcation that happened in legget street at 28 july .
SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' and month = 7 and day = 28;

-- get the all information about account number from people id
SELECT * FROM people WHERE id = (
    SELECT person_id FROM bank_accounts where account_number = 49610011);

-- get all the information about the the calls that our suspect made during the day of the theft.
SELECT * FROM phone_calls WHERE caller = '(375) 555-8161' and day = 28 and month = 7;

-- get the information of the ACCOMPLICE using tje phone number we got
SELECT * FROM people WHERE phone_number = '(375) 555-8161';

-- get the flight id where the suspect's passport is used
SELECT * FROM flights WHERE id in (
    SELECT flight_id FROM passengers WHERE passport_number = 5773159633);

-- get the original or destination airport using this query
SELECT * FROM airports WHERE id = 8;
