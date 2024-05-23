using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    public class Product
    {
        public string Name { get; set; }
        public decimal Price { get; set; }
        public int Quantity { get; set; }
        public string ManufacturerCode { get; set; }
    }

    public class Warehouse
    {
        public string Name { get; set; }
        public int Area { get; set; }
        public int ForkliftsCount { get; set; }
        public int YearBuilt { get; set; }
    }

    public class Manufacturer
    {
        public string Name { get; set; }
        public string Director { get; set; }
        public string Code { get; set; }
    }
    class Aircraft
    {
        public string Type { get; set; }
        public int PayloadCapacity { get; set; }
        public int MaxRange { get; set; }
        public int Wingspan { get; set; }
        public int TakeoffLength { get; set; }
        public string CompanyCode { get; set; }
    }

    class Helicopter
    {
        public string Type { get; set; }
        public int PayloadCapacity { get; set; }
        public int MaxAltitude { get; set; }
        public int FlightRange { get; set; }
        public string CompanyCode { get; set; }
    }

    class Airline
    {
        public string Name { get; set; }
        public string OfficeLocation { get; set; }
        public DateTime FoundationDate { get; set; }
        public string CompanyCode { get; set; }
    }
    class Truck
    {
        public string Brand { get; set; }
        public int LoadCapacity { get; set; }
        public DateTime ProductionDate { get; set; }
        public DateTime RepairDate { get; set; }
        public string LicensePlate { get; set; }
        public string ParkCode { get; set; }
    }

    class Taxi
    {
        public string Brand { get; set; }
        public int Seats { get; set; }
        public DateTime ProductionDate { get; set; }
        public string LicensePlate { get; set; }
        public string ParkCode { get; set; }
    }

    class CarPark
    {
        public string Name { get; set; }
        public string Address { get; set; }
        public int Area { get; set; }
        public string Code { get; set; }
    }
    static void Main()
    {
        List<Product> products = new List<Product>
        {
            new Product { Name = "Product1", Price = 10, Quantity = 100, ManufacturerCode = "M1" },
            new Product { Name = "Product2", Price = 20, Quantity = 50, ManufacturerCode = "M2" },
            new Product { Name = "Product3", Price = 15, Quantity = 75, ManufacturerCode = "M1" }
        };

        List<Warehouse> warehouses = new List<Warehouse>
        {
            new Warehouse { Name = "Warehouse1", Area = 1000, ForkliftsCount = 5, YearBuilt = 2000 },
            new Warehouse { Name = "Warehouse2", Area = 1500, ForkliftsCount = 3, YearBuilt = 2010 }
        };

        List<Manufacturer> manufacturers = new List<Manufacturer>
        {
            new Manufacturer { Name = "Manufacturer1", Director = "Director1", Code = "M1" },
            new Manufacturer { Name = "Manufacturer2", Director = "Director2", Code = "M2" }
        };
        List<Aircraft> aircrafts = new List<Aircraft>
        {
            new Aircraft { Type = "Boeing 737", PayloadCapacity = 30000, MaxRange = 5000, Wingspan = 35, TakeoffLength = 2000, CompanyCode = "AC001" },
            new Aircraft { Type = "Airbus A320", PayloadCapacity = 28000, MaxRange = 4800, Wingspan = 36, TakeoffLength = 2100, CompanyCode = "AC002" },
            new Aircraft { Type = "Boeing 747", PayloadCapacity = 80000, MaxRange = 7500, Wingspan = 64, TakeoffLength = 3000, CompanyCode = "AC001" }
        };
        List<Helicopter> helicopters = new List<Helicopter>
        {
            new Helicopter { Type = "Bell 407", PayloadCapacity = 1500, MaxAltitude = 6000, FlightRange = 500, CompanyCode = "HC001" },
            new Helicopter { Type = "Sikorsky S-92", PayloadCapacity = 5000, MaxAltitude = 10000, FlightRange = 1000, CompanyCode = "HC002" },
            new Helicopter { Type = "Eurocopter EC135", PayloadCapacity = 2000, MaxAltitude = 8000, FlightRange = 700, CompanyCode = "HC001" }
        };

        List<Airline> airlines = new List<Airline>
        {
            new Airline { Name = "Delta Airlines", OfficeLocation = "Atlanta", FoundationDate = new DateTime(1920, 5, 30), CompanyCode = "AC001" },
            new Airline { Name = "United Airlines", OfficeLocation = "Chicago", FoundationDate = new DateTime(1931, 4, 6), CompanyCode = "AC002" },
            new Airline { Name = "American Airlines", OfficeLocation = "Fort Worth", FoundationDate = new DateTime(1930, 4, 15), CompanyCode = "AC003" }
        };

        List<Truck> trucks = new List<Truck>
        {
            new Truck { Brand = "Volvo", LoadCapacity = 5000, ProductionDate = new DateTime(2015, 5, 20), RepairDate = new DateTime(2019, 10, 15), LicensePlate = "ABC123", ParkCode = "001" },
            new Truck { Brand = "MAN", LoadCapacity = 7000, ProductionDate = new DateTime(2018, 8, 10), RepairDate = new DateTime(2021, 3, 27), LicensePlate = "DEF456", ParkCode = "002" }
        };

        List<Taxi> taxis = new List<Taxi>
        {
            new Taxi { Brand = "Toyota", Seats = 4, ProductionDate = new DateTime(2017, 3, 12), LicensePlate = "GHI789", ParkCode = "002" },
            new Taxi { Brand = "Hyundai", Seats = 3, ProductionDate = new DateTime(2019, 6, 5), LicensePlate = "JKL012", ParkCode = "001" }
        };

        List<CarPark> carParks = new List<CarPark>
        {
            new CarPark { Name = "City Park", Address = "123 Main Street", Area = 10000, Code = "001" },
            new CarPark { Name = "Central Park", Address = "456 Park Avenue", Area = 15000, Code = "002" }
        };

        Console.WriteLine("Продукты\n");

        var sortedProducts = products.OrderBy(p => p.Price);
        foreach (var product in sortedProducts)
        {
            Console.WriteLine($"Продукт: {product.Name}, Цена: {product.Price}");
        }

        var groupedWarehouses = warehouses.GroupBy(w => new { w.ForkliftsCount, w.YearBuilt });
        foreach (var group in groupedWarehouses) 
        {
            Console.WriteLine($"Количество погрузчиков: {group.Key.ForkliftsCount}, Год постройки: {group.Key.YearBuilt}, Склады: {group.Count()}");
        }

        var totalForklifts = warehouses.Sum(w => w.ForkliftsCount);
        Console.WriteLine($"Общее количество погрузчиков: {totalForklifts}");

        var productManufacturerJoin = from p in products
                                      join m in manufacturers on p.ManufacturerCode equals m.Code
                                      select new { ProductName = p.Name, ManufacturerName = m.Name };

        foreach (var item in productManufacturerJoin)
        {
            Console.WriteLine($"Продукт: {item.ProductName}, Производитель: {item.ManufacturerName}");
        }
        Console.WriteLine("Самолёты:\n");

        var sortedAircrafts = aircrafts.OrderBy(a => a.PayloadCapacity);
        foreach (var aircraft in sortedAircrafts)
        {
            Console.WriteLine($"Тип: {aircraft.Type}, Грузоподъемность: {aircraft.PayloadCapacity}");
        }

        var groupedHelicopters = helicopters.GroupBy(h => new { h.MaxAltitude, h.FlightRange });
        foreach (var group in groupedHelicopters)
        {
            Console.WriteLine($"Максимальная высота: {group.Key.MaxAltitude}, Дальность полета: {group.Key.FlightRange}");
            foreach (var helicopter in group)
            {
                Console.WriteLine($"    Тип: {helicopter.Type}");
            }
        }
        var aircraftCount = aircrafts.Count();
        Console.WriteLine($"Количество самолётов в авиакомпании: {aircraftCount}");

        var joinedData = aircrafts.Join(airlines, a => a.CompanyCode, al => al.CompanyCode, (a, al) => new { AircraftName = a.Type, AirlineName = al.Name });
        foreach (var data in joinedData)
        {
            Console.WriteLine($"Самолёт: {data.AircraftName}, Авиакомпания: {data.AirlineName}");
        }

        Console.WriteLine("Автомобили:\n");

        var sortedTrucks = trucks.OrderBy(t => t.ProductionDate);
        Console.WriteLine("Грузовые автомобили отсортированные по дате выпуска:");
        foreach (var truck in sortedTrucks)
        {
            Console.WriteLine($"{truck.Brand} - {truck.ProductionDate}");
        }

        var groupedTaxis = taxis.GroupBy(t => new { t.Brand, t.ProductionDate });
        Console.WriteLine("\nТакси сгруппированные по марке и дате выпуска:");
        foreach (var group in groupedTaxis)
        {
            Console.WriteLine($"Марка: {group.Key.Brand}, Дата выпуска: {group.Key.ProductionDate}");
            foreach (var taxi in group)
            {
                Console.WriteLine($"Гос. номер: {taxi.LicensePlate}, Сидений: {taxi.Seats}");
            }
        }

        var taxiCountInCarParks = taxis.GroupBy(t => t.ParkCode)
                                       .Select(group => new
                                       {
                                           ParkCode = group.Key,
                                           TaxiCount = group.Count()
                                       });
        Console.WriteLine("\nКоличество такси в каждом автопарке:");
        foreach (var item in taxiCountInCarParks)
        {
            Console.WriteLine($"Автопарк: {item.ParkCode}, Количество такси: {item.TaxiCount}");
        }

        var query = from truck in trucks
                    join park in carParks on truck.ParkCode equals park.Code
                    select new { ParkName = park.Name, TruckType = "Грузовой автомобиль", LicensePlate = truck.LicensePlate };

        Console.WriteLine("\nСоединенные данные:");
        foreach (var item in query)
        {
            Console.WriteLine($"Автопарк: {item.ParkName}, Тип автомобиля: {item.TruckType}, Гос. номер: {item.LicensePlate}");
        }
    }
}